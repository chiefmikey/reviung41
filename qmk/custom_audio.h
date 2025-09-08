#pragma once

#include "quantum.h"
#include "musical_notes.h"

#ifndef ZELDA_SECRET
#define ZELDA_SECRET \
    Q__NOTE(_A4), Q__NOTE(_B4), Q__NOTE(_CS5), Q__NOTE(_D5), \
    Q__NOTE(_E5), Q__NOTE(_FS5), Q__NOTE(_GS5), Q__NOTE(_A5)
#endif

#ifndef ZELDA_PUZZLE
#define ZELDA_PUZZLE \
    Q__NOTE(_A4), Q__NOTE(_B4), Q__NOTE(_CS5), Q__NOTE(_D5), \
    Q__NOTE(_E5), Q__NOTE(_FS5), Q__NOTE(_GS5), Q__NOTE(_A5)
#endif

#ifndef ZELDA_ITEM_FANFARE
#define ZELDA_ITEM_FANFARE \
    Q__NOTE(_C5), Q__NOTE(_E5), Q__NOTE(_G5), Q__NOTE(_C6), \
    Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_C7)
#endif

#ifndef SONIC_RING
#define SONIC_RING \
    E__NOTE(_E6), E__NOTE(_GS6), E__NOTE(_B6), E__NOTE(_E7), \
    E__NOTE(_GS7), E__NOTE(_B7), E__NOTE(_E8)
#endif

#endif
