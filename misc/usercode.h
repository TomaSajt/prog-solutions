#include <stdint.h>

struct IpcBotInfo {
    long long bot_id; // ID of the bot
    char bot_name[64]; // the first 64 characters of the bot's name
};
struct IpcServerConfig {
    int snake_boost_steps; // number of steps a snake moves when boosting
    float snake_turn_radius_factor; // Multiplied with your segment radius to determine the inner turn radius

    float snake_pull_factor; // Pull-together factor (determines how fast segments move to the center of a loop)

    float snake_conversion_factor; // how much of a snake's mass is converted to food when it dies

    float snake_segment_distance_factor;   // segment distance = (mass * factor)^exponent
    float snake_segment_distance_exponent; // segment distance = (mass * factor)^exponent

    float snake_consume_range; // consume range multiplier (multiplied with segment radius)

    float snake_boost_loss_factor;    // Multiplied with the snakes mass to determine how much mass is lost per step while boosting
    float snake_survival_loss_factor; // This part of your mass is dropped every step (to limit snake growth)

    float snake_self_kill_mass_theshold; // Mass below which a snake dies through starvation

    float food_decay_step; // Food decays by this value each step

    float log_credits_per_frame; // How many log messages you can send per step
    float log_initial_credits;   // How many log messages you can send right after startup
    float log_max_credits;       // You can send at most this many messages in a row
};
struct IpcSelfInfo {
    float segment_radius; // Radius of your snake's segments
    float mass;           // Your snake's current mass
    float sight_radius;   // Radius around your snake's head in which you can see food and segments
    float consume_radius; // Radius around your snake's head in which food is consumed.

    uint32_t start_frame;   // Step number when your snake was spawned
    uint32_t current_frame; // Current step number

    float speed;          // Distance per step
    float max_step_angle; // Maximum direction change in this step

    float consumed_natural_food;          // Amount of naturally spawned food your snake consumed
    float consumed_food_hunted_by_self;   // Amount of food you consumed and that was created from snakes you killed
    float consumed_food_hunted_by_others; // Amount of food you consumed and that was created from snakes others killed (carrion)
};
struct IpcFoodInfo {
    float x; // x coordinate
    float y; // y coordinate
    float val; // how much mass the food item contains
    float dir; // direction your snake needs to take to go directly to the food item
    float dist; // distance between the food item and your snake's head
};
struct IpcSegmentInfo {
    float x; // x coordinate
    float y; // y coordinate
    float r; // radius of segment
    int idx; // id of the snake
    long long bot_id; // this segment is the `idx`-th segment of the snake
    float dir; // direction your snake needs to take to go directly to the segment
    float dist; // distance between segment and your snake's head
    bool is_self; // whether this segment belongs to your snake
};

struct Api {
    size_t getSegmentCount();
    IpcSegmentInfo* getSegments();
    size_t getFoodCount();
    IpcFoodInfo* getFood();
    float angle;
    bool boost;
    void log(const char* msg);
    void clearColors();
    void addColor(uint8_t r, uint8_t g, uint8_t b);
    size_t getBotsCount();
    IpcBotInfo* getBots();
    IpcServerConfig getServerConfig();
    IpcSelfInfo* getSelfInfo();

};