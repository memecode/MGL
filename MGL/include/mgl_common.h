#pragma once

#if __APPLE__
    #define GLAPI extern __attribute__(( visibility("default") ))
#else
    #define GLAPI extern
#endif
