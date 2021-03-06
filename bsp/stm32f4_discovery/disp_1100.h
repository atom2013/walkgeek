/*
 * disp_1100.h
 *
 * Copyright (c) 2012, 2013, 2014, Oleg Tsaregorodtsev
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DISP_1100_H_
#define DISP_1100_H_

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/* Exported constants --------------------------------------------------------*/
#define DISP_X_COUNT                96
#define DISP_Y_COUNT                65
#define DISP_Y_PER_ROW              8

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define DISP_ROW_COUNT              ((DISP_Y_COUNT+DISP_Y_PER_ROW)/DISP_Y_PER_ROW)
#define DISP_COL_COUNT              ((DISP_X_COUNT)/(5+1))

#define CTRL_COL(code) (code % 8)
#define CTRL_ROW(code) (code / 8)
#define CTRL(row, col) (row*8 + col)
#define SYS_MATRIX_SIZE ((CTRL_MAX / 8) + 1)

/* Exported functions ------------------------------------------------------- */
void Disp1100_Init(FunctionalState irq_enabled);

void Disp1100_SetXRow(u8 x, u8 row);

void Disp1100_SendData(u8 byte);

#endif /* DISP_1100_H_ */
