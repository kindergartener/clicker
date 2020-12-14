#ifndef CONFIG_H
#define CONFIG_H

class c_options {
public:
    int place_key = 0;
    int attack_key = 0;
    int place_cps = 0;
    int attack_cps = 0;
    bool toggle = false;
    bool humanize = false;
};

extern c_options config;

#endif // CONFIG_H
