// You can use the entire C/C++ standard library, just add the relevant
// #includes. We recommend math.h ;-)


// Limits
// your 64 MB Ram including overhead from c and the snake api


#include "usercode.h"
#include <bits/stdc++.h>
#define PI 3.1415926535
using namespace std;

bool init(Api* api) {
    // remove the default color
    api->clearColors();

    // These 4 colors are repeated as many times as needed to color all segments.
    bool asd = false;
    for (int i = 0; i < 200;i++) {
        if (rand() % 12 == 0) asd = !asd;
        if (asd) api->addColor(20, 20, 20);
        else api->addColor(255, 255, 255);
    }
    // note: you can add at most 200 colors

    return true;
}

float getMassOf(IpcFoodInfo food, const IpcSelfInfo* selfInfo) {
    return food.val / (1 + max(max(food.dist - selfInfo->consume_radius, 0.0f) / selfInfo->speed, abs(food.dir) / selfInfo->max_step_angle));
}

bool braked = false;

bool step(Api* api) {
    auto selfInfo = api->getSelfInfo();
    string s = "";
    s += " maxAngle: " + to_string(selfInfo->max_step_angle / PI * 180);
    s += " mass: " + to_string(selfInfo->mass);
    //api->log(s.c_str());
    // let's start by moving in a large circle. Please note that all angles are
    // represented in radians, where -π to +π is a full circle.
    api->angle = 0;

    //[bool] api->boost  - set this variable to run twice as fast, if you do so your snake drops mass fast

    // check for other snakes
    bool no_brake = true;
    bool escape_boost = false;
    float avg_x = 0; float avg_y = 0; float avg_mass = 0; float curr_mass = 0;
    float hatar = selfInfo->speed / selfInfo->max_step_angle + selfInfo->segment_radius;
    for (size_t i = 0; i < api->getSegmentCount(); i++) {
        const auto& seg = api->getSegments()[i];

        //[float] seg.x -- x coordinate
        //[float] seg.y -- y coordinate
        //[float] seg.r -- radius of segment
        //[float] seg.dir -- direction your snake needs to take to go directly to the segment
        //[float] seg.dist -- distance to your snakes head
        //[int] seg.bot_id -- id of the bot
        //[long long] seg.idx -- the
        //[bool] seg.is_self -- does this segment belong to me
        if (escape_boost) {
            escape_boost = api->boost = false;
        }
        if (!seg.is_self) {
            if (seg.dist < hatar * 2.5 + seg.r) {
                no_brake = false;
                avg_x += cos(seg.dir) / (1 + seg.dist);
                avg_y += sin(seg.dir) / (1 + seg.dist);
                avg_mass += (1 + seg.dist);
            }
            if (seg.dist < hatar * 1.5 + seg.r) {
                if (!escape_boost)
                    api->log("Oh no, I'm going to die!");
                api->boost = true;
                escape_boost = true;
            }

        }
    }
    if (no_brake) {
        if (braked) api->log("kereses...");
        auto foods = api->getFood();
        auto food_count = api->getFoodCount();
        if (food_count > 0) {
            int maxI = 0;
            int minI = 0;
            avg_x = 0; avg_y = 0; avg_mass = 0; float curr_mass = 0;
            for (size_t i = 0; i < food_count; i++) {
                const auto& food = foods[i];

                if (foods[maxI].val / (1 + max(max(foods[maxI].dist - selfInfo->consume_radius, 0.0f) / selfInfo->speed, abs(foods[maxI].dir) / selfInfo->max_step_angle)) < getMassOf(food, selfInfo)) {
                    maxI = i;
                }
                if (foods[minI].dist > food.dist) minI = i;
                curr_mass = food.val / sqrt(1 + food.dist);//getMassOf(food, selfInfo);
                avg_mass += curr_mass; avg_x += cos(food.dir) * curr_mass; avg_y += sin(food.dir);
                //[float] food.x -- x coordinate
                //[float] food.y -- y coordinate
                //[float] food.val -- how much mass the food gives to your snake
                //[float] food.dir -- direction your snake needs to take to go directly to the food
                //[float] food.dist -- distance to your snakes head

            }
            api->angle = foods[minI].dist < selfInfo->consume_radius || (avg_x * avg_x + avg_y * avg_y) / (avg_mass * avg_mass)>1 / selfInfo->consume_radius ? atan2(avg_y, avg_x) : foods[maxI].dir;
        }
    }
    else {
        if (!braked) api->log("MENEKULES");
        if (!escape_boost)
            api->angle = atan2(-avg_y, -avg_x);
        else
            api->angle = atan2(avg_x + avg_y, -avg_y + avg_x);
    }
    braked = !no_brake;

    // Signal that everything is ok. Return false here if anything goes wrong but
    // you want to shut down cleanly.
    return true;
}