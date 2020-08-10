/*
 * main.c
 *
 *  Created on: 2020 Aug 08 20:28:24
 *  Author: FORGE-15R
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

  // data type declaration
  	volatile uint32_t pin_status = 0;


// function prototype declaration
/*	void clamp_open_IRQHandler(void);
	void clamp_close_IRQHandler(void);
	void clamp_up_IRQHandler(void);
	void clamp_down_IRQHandler(void);*/


int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}


void clamp_open_IRQHandler(void)
{
     pin_status = PIN_INTERRUPT_GetPinValue(&clamp_open);
     if(pin_status == 1)
     {
 	  	// sets the duty to 2%.
    	// clamp open
    	 PWM_SetDutyCycle(&pwm_clamp_open_and_close,200);
     }

     else
     {
    	 // sets the channel duty to 10%.
    	 // clamp maintain
    	 PWM_SetDutyCycle(&pwm_clamp_open_and_close,0);
     }

 	pin_status = 0;

}

void clamp_close_IRQHandler(void)
{
     pin_status = PIN_INTERRUPT_GetPinValue(&clamp_close);
     if(pin_status == 1)
     {
 	  	// sets the channel duty to 10%.
    	// clamp close
    	 PWM_SetDutyCycle(&pwm_clamp_open_and_close,1200);
     }

     else
     {
    	 // sets the channel duty to 10%.
    	 // clamp maintain
    	 PWM_SetDutyCycle(&pwm_clamp_open_and_close,0);
     }


	pin_status = 0;

}
void clamp_up_IRQHandler(void)
{

     {
 	  	// sets the duty to 2%.
    	// clamp open
    	 PWM_SetDutyCycle(&pwm_clamp_up_and_down,200);
     }

}

void clamp_down_IRQHandler(void)
{

     {
 	  	// sets the channel duty to 10%.
    	// clamp close
    	 PWM_SetDutyCycle(&pwm_clamp_up_and_down,900);
     }

}
