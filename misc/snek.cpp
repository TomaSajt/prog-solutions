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
    api->addColor(63, 63, 63);
    // note: you can add at most 200 colors

    return true;
}


bool step(Api* api) {
    auto selfInfo = api->getSelfInfo();
    int time = selfInfo->current_frame - selfInfo->start_frame;
    string s = "";
    s += " maxAngle: " + to_string(selfInfo->max_step_angle / PI * 180);
    s += " mass: " + to_string(selfInfo->mass);
    s += " radius: " + to_string(selfInfo->consume_radius);
    // represented in radians, where -π to +π is a full circle.

    //[bool] api->boost  - set this variable to run twice as fast, if you do so your snake drops mass fast
    bool panic = false;
    // check for other snakes
    vector<int> idk;
    for (size_t i = 0; i < api->getSegmentCount(); i++) {
        const auto& seg = api->getSegments()[i];
        int dist = seg.dist - seg.r - selfInfo->segment_radius;
        if (!seg.is_self && dist < 20 / selfInfo->max_step_angle) {
            panic = true;
            api->angle = PI / 2 + seg.dir;
            api->boost = true;
            if (api->angle > PI) api->angle -= 2 * PI;
            api->log("Oh no, I'm going to die!");
            break;
        }
    }
    //api->log(s.c_str());
    if (!panic) {

        api->boost = false;
        int divs = 16;
        vector<float> dirs(divs, 0);
        for (size_t i = 0; i < api->getFoodCount(); i++) {
            const auto& food = api->getFood()[i];
            int dir = (int)((food.dir + PI) / (2 * PI) * divs);
            if (dir < 0)dir = 0;
            if (dir >= divs) dir = divs - 1;
            dirs[dir] += food.val / sqrtf(food.dist);
        }
        string a = "dirs: ";
        for (int i = 0; i < divs;i++) a += to_string(dirs[i]) + " ";
        //api->log(a.c_str());
        a = "bestDir: ";
        int bestDir = max_element(dirs.begin(), dirs.end()) - dirs.begin();
        a += to_string(bestDir);
        //api->log(a.c_str());
        api->angle = bestDir * 2 * PI / divs - PI;
    }

    // Signal that everything is ok. Return false here if anything goes wrong but
    // you want to shut down cleanly.
    return true;
}