#include <stdint.h>

typedef void (*KernelMain)(void);

// BPP is BYTES PER PIXEL

#define FB_Base 0x100000
#define Width 800
#define Height 575
#define BPP 4

void DrawBG(void) {
    uint32_t* FrameBuffer = (uint32_t*)FB_BASE;

    for (int Y = 0; Y < Height; Y++) {
        for (int X = 0; X < Width; X++) {
            int Index = Y * Width + X;

            FrameBuffer[Index] = 0xFF0000FF;
        }
    }
}

void BootMain(void) {
    DrawBG();
    
    KernelMain Kernel = (KernelMain)0x8000;

    Kernel();
}
