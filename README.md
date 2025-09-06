# STM32-BlinkDemo

Minimal **STM32 HAL** snippet demonstrating **LED blink** and **button** input. Use **STM32CubeMX** to generate a project and then drop the logic into your `main.c`.

## How it Works
1. Configure one **LED** GPIO as Output and one **Button** GPIO as Input with Pull-Up.
2. In the main loop, read the button:
   - If pressed (active-low), toggle LED quickly.
   - Else, toggle LED slowly.
3. Use `HAL_Delay(...)` for simple blocking delays.

## File Structure
```
STM32-BlinkDemo/
└─ main.c
```

## Build
- Generate and build via your preferred toolchain (Keil, IAR, or GCC/Makefile).
- Flash with ST-Link.

## Next Steps (Optional)
- Switch to **interrupt**-based button handling (EXTI).
- Implement **software debouncing**.
- Blink different patterns based on button state.
