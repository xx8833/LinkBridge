#include "Cell.h"

int Cell::Load(string input)
{
    string args = input.substr(1);
    switch (input[0]) {
        case 'B':
            bridge = true;
            if(args.find('#') != string::npos)
            {
                color = (int)strtol(args.substr(0,2).c_str(),nullptr,10);
                colorb = (int)strtol(args.substr(3,2).c_str(),nullptr,10);
            }
            break;
        case 'S':
            is_source = true;
            color = (int)strtol(args.substr(1).c_str(),nullptr,10);
        case 'N':
            is_source = false;
            color = (int)strtol(args.substr(1).c_str(),nullptr,10);
        default:
            cerr << "Can not Load cell. Args: " << input;
            break;
    }
    return 0;
}