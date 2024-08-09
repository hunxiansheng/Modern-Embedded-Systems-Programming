/*****************************************************************************
* BSP for EK-TM4C123GXL with uC/AO active-object framework
*****************************************************************************/
#ifndef BSP_H
#define BSP_H

void BSP_init(void);
void BSP_start(void);

void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

/*---------------------------------------------------------------------------*/
enum EventSignals {
    BUTTON_PRESSED_SIG = USER_SIG,
    BUTTON_RELEASED_SIG,
    TIMEOUT_SIG,
    /* ... */
};

/* Active objects... */
extern Active *AO_BlinkyButton;

#endif /* BSP_H */
