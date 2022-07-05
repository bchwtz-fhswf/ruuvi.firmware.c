#ifndef MODEL_22_NNOM_H
#define MODEL_22_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_22_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (10)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (192)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (32)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.24075012569983611f, -0.24075012569983611f, 0.0f, 0.24074851273755382f, -0.0f, 0.25f, -0.5f, 0.25f, 0.49040304612512053f, -0.24075173866211835f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_4_KERNEL_0 {21, -33, -20, -17, 1, -25, 22, -25, -29, -5, -35, -40, -36, 51, -13, -4, 29, -28, -9, -10, -1, 25, 3, 34, 32, 1, -13, 1, 1, 6, -22, -3, 0, -9, -5, 30, -32, 5, 25, 13, 14, -21, 9, -6, -43, 45, 27, -29, -4, 13, -51, -53, -14, -11, 15, 22, 43, 31, 16, 5, -9, -16, -12, -3, -48, 38, -5, 30, 32, -12, 44, -35, -11, 42, -25, -4, -9, -39, -10, 4, 28, -16, 32, 14, -20, 31, -16, 20, -22, -18, 15, -39, 17, -47, 33, 4, 0, 17, -11, -1, -2, -15, 7, -6, 10, -5, -3, -2, -42, -40, 32, -34, 15, 29, 12, 12, -19, -10, 9, -5, -31, 23, -13, -18, -4, -1, 41, 19, 1, 20, -3, -61, 29, -51, -11, 15, -40, 15, 13, -23, 27, -1, -14, 5, 24, 24, -6, -13, 9, 7, -28, -1, -2, 2, -11, 12, 58, 16, 19, 23, -27, -14, -28, -45, 8, -6, -31, 13, 66, 19, 12, -12, -26, -29, -13, 7, -14, 13, -31, 3, -53, 61, 2, -3, 4, -19, 19, -8, 6, -10, 25, -22, 45, 40, -9, 6, -12, -2, 15, 3, 6, -14, -60, -38, 7, -11, 2, 9, 17, 3, -5, 17, -14, 47, -12, -67, 17, 30, 31, 2, -11, -8, 14, -15, 59, 7, 50, -8, 32, 1, -22, 1, 31, 44, 46, 2, -43, -32, -12, -32, 30, -26, 18, -19, -7, -2, 17, 12, -22, -28, -43, 70, -1, 13, -11, -67, -3, 23, 14, 32, -13, -29, 31, 44, -26, -47, -41, 52, 1, -10, -6, 0, -2, -4, -3, 1, 3, -3, -10, 11, 21, -8, -22, -30, 34, -22, -15, 0}

#define TENSOR_CONV2D_4_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_4_BIAS_0 {-20, -10, 95, -28, -5, -5, -8, 21, 125, -92, -54, -87, 13, -83, -4, -6, -5, -50, -13, -51, -5, -115, -50, 19}

#define TENSOR_CONV2D_4_BIAS_0_DEC_BITS {10}

#define CONV2D_4_BIAS_LSHIFT {3}

#define CONV2D_4_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_5_KERNEL_0 {2, -10, -7, 8, -3, -77, -8, -15, 6, -43, 5, 43, 21, 16, 11, -18, 11, 9, 17, -80, -34, 8, 28, -4, 2, -55, 5, 69, -2, -17, -18, 0, -1, 22, -52, 14, 5, 4, 16, -93, 10, 8, 18, 23, 4, -16, -2, 1, 4, -47, -1, -39, 0, 12, -16, -18, 7, 2, -1, 9, 16, -40, -39, -19, 21, -9, -12, -13, -25, 6, -30, -2, 22, 0, 5, 9, -25, -93, -9, -17, 6, -16, -4, 30, -4, -15, 22, -21, 16, 16, -31, 9, 9, 5, 11, 9, 4, -10, 12, 21, -121, -13, -79, -12, -3, -5, -20, 17, -19, -35, -92, -92, -55, -47, -25, 4, -1, 1, 2, -10, -9, 20, 6, 19, -29, -14, -2, -25, 2, 9, -24, 39, 0, -93, -101, 13, -57, 2, -2, -3, -45, -1, -19, -9, 0, 26, 10, 11, -48, -65, -16, -1, 15, -33, 18, 4, 2, -16, -7, -34, -29, 21, 26, -47, 25, 82, 11, 3, -43, -20, 3, 48, -10, 12, 25, 2, -7, 4, 47, 37, -5, 14, 5, -6, 37, 2, 15, -45, 18, 14, 32, 7, 27, 6, 0, -28, -22, -11, -3, -48, -7, 15, -24, 44, 4, 26, 37, 4, 11, -10, 26, 33, -2, -6, 25, -23, -5, 15, -7, -17, -3, -3, 11, 3, 6, -25, 17, -1, 17, 15, 34, 22, 15, -46, 8, 19, -21, -27, 9, 8, 0, 14, -3, 19, -27, -7, -41, -25, -8, 14, -2, 34, -39, -29, -11, 29, 25, -5, -78, -1, 11, -8, 9, 2, -12, 12, -8, 20, -6, -21, -2, -12, -9, 10, 7, 1, -22, -56, 1, 10, -39, -5, -42, -14, -49, 29, 3, -18, 10, 18, 0, -3, -79, 3, -25, 8, -1, 37, -1, 6, -20, -14, -11, 0, 8, -22, 30, 12, -43, -22, 24, -17, 0, -2, -9, 9, -28, -9, -11, 2, -13, 10, -20, 13, -2, -2, 12, 10, -12, -19, 4, -6, -20, -1, -3, 4, 8, 17, -16, 27, 7, -4, 9, -10, -1, 28, 19, 56, -10, 0, 0, 19, 29, 16, 33, -10, -28, -17, 30, -10, 24, -35, 1, 6, 5, -60, -52, -22, 12, 4, 2, 15, 9, 23, 23, 13, 11, -16, -8, -33, 11, 33, 6, -17, -17, -25, 23, 27, 5, 5, -1, -16, 4, -1, -45, -20, 2, -10, 6, -14, 1, -18, -1, -4, 15, 9, -29, 9, 30, 37, -6, 22, 17, 19, 16, -1, 1, -19, 6, -16, -3, -2, -1, 11, -1, 9, -1, 23, 6, -15, 22, 14, -11, 2, -16, -12, 11, 12, 13, -11, -5, 27, 0, -2, -9, -23, 48, 53, 10, -31, -1, 3, -9, 1, -10, -7, 36, 23, 7, 8, 19, 13, 0, -15, 12, 29, 30, 10, 7, 35, 13, 19, 22, -4, 3, -23, 30, -30, -10, -7, -30, -28, 11, -7, 20, -2, 43, -2, 5, 5, -37, -5, 1, -12, 25, 26, 20, -15, -10, 8, 15, -38, -13, 5, -6, 34, 1, -25, 29, 7, 2, -23, -2, 16, -35, -36, -12, -4, 15, 42, 11, -32, -16, -10, 0, -19, 20, -12, -11, -18, 3, -35, -14, -13, -8, 0, 7, -16, -55, -32, 14, -3, 20, 10, 20, -31, -3, -33, 44, -39, 21, -10, 0, 5, 0, 22, 19, 13, 57, -3, -4, 0, -45, -11, -6, -11, 9, 39, -10, -23, -1, 11, -14, 0, -3, -3, 19, -9, 14, -13, -11, 1, -7, 10, 7, -8, -13, 5, 0, -4, -12, -11, 1, 4, -4, 20, -15, 0, -21, 9, -10, 15, 9, 10, 29, 22, 2, 20, 9, 0, 15, 4, 8, 3, 1, 13, 17, 16, -7, 1, 10, 7, 18, -10, 36, -6, 14, -11, -12, 12, 7, 9, 14, 1, -2, 0, 20, 9, -1, 4, 3, -19, -6, 24, -22, -20, -16, 12, 21, 8, 5, 9, 1, 13, 2, -2, 10, 10, 6, 17, 11, 24, 12, -12, 16, 11, 0, 26, 4, -10, 14, -4, 8, -7, 15, -2, 5, -21, 14, 34, 17, -5, -2, -7, -1, -11, -23, -2, -27, -9, -6, -21, -17, -8, 1, 19, -19, 25, 6, 2, -7, -23, -14, -26, 3, 28, -14, -4, 2, 10, 16, 12, -5, -13, -9, -6, -6, 2, -9, -13, 3, 0, 12, -19, -11, -38, 7, 1, 5, -16, -41, -34, 15, 14, -8, -18, -36, -53, -11, -49, -26, 16, -24, 3, -19, 1, 16, -11, -3, 12, -3, 3, 9, -10, 1, -4, -4, 16, 3, -12, -22, -16, 1, -15, -14, -17, -12, 16, -17, 14, 3, 16, 25, -22, 14, -1, 4, 26, -19, 6, 1, 34, 32, 49, 28, -60, 5, -1, 31, 51, -4, -8, 24, -26, 2, 22, 13, -5, -14, 14, -4, 1, 21, 1, 10, 32, 53, -17, 9, 30, -8, 39, 12, -26, 30, -24, 12, 14, 3, 10, -19, -2, 26, 7, -11, 17, 11, 40, 15, -2, -3, 29, 2, 2, 16, -13, -3, 28, 19, -10, -3, 34, 1, 26, -9, 1, -17, -55, -18, 35, -10, 33, 7, 28, 33, 25, 1, 30, -19, -17, 8, -9, 19, 7, -12, 9, 4, 4, 14, -8, 39, 7, 6, -16, -77, 11, 1, -3, 5, 18, 18, -17, -27, -14, 17, -2, 9, 14, -19, 7, -3, 1, -17, -20, -11, -25, 0, 8, -18, 9, 2, 10, 37, 26, -1, -45, 0, -24, 9, 2, 22, -18, 6, 9, 4, -54, -3, -11, 1, 6, 12, -31, -7, -55, 12, -31, -15, -8, -16, -30, -9, -19, 18, -21, 0, -30, -22, -22, 5, -13, -5, -4, 23, 1, -2, 3, -29, 1, -7, 0, -6, 26, -4, -36, 12, -9, -39, -23, 7, 24, -15, 6, 7, 15, 6, 24, 13, -3, 9, 16, -4, 24, 6, -16, 10, 20, 8, 10, 12, 21, 25, -6, 23, 3, 13, 34, -5, 27, 2, -18, -5, -4, 13, 14, 21, 3, 3, -1, 12, 7, 15, 0, 13, -1, -14, 37, 4, 20, 1, -2, -1, 35, 6, -3, -11, -17, -6, -3, -30, 9, -6, -7, 32, 26, 23, -9, -28, 1, 11, 9, 28, 11, 8, 13, -8, -6, 17, 3, 3, 5, 4, 14, 13, -22, 6, 0, 4, 6, -3, -18, -4, 4, 14, 19, 15, 0, 13, 3, 5, -1, -15, 18, -5, 0, 3, 1, 4, -3, 18, 9, 8, 10, 28, 10, 22, -28, -2, -25, 14, -2, -7, 0, -4, -4, 14, -2, 2, 4, -9, 17, 22, -6, 3, -6, 14, 3, 3, 2, 7, -8, 14, 19, 0, -7, -4, -4, -3, 13, 4, 22, 23, 13, 1, 36, -10, 3, 5, 31, 22, 30, 36, 13, 12, -6, 6, -21, 0, 21, 10, 37, 7, 6, -2, -5, 5, 9, 8, 1, -17, 16, 1, -6, -4, 10, 26, 12, 3, 25, 15, 15, 15, -2, -16, -57, 18, 20, 21, 5, -11, -14, -3, -19, -25, 7, 5, 18, 37, -34, -33, 7, -80, 30, 9, -4, 11, -9, 41, 9, -6, -28, -14, 3, -12, -9, -4, 5, -32, 32, -6, -8, -8, -6, 16, -16, 3, 43, -40, 2, 15, -5, -48, -86, 2, 6, 40, -1, 13, 5, 8, -20, 20, 5, 15, 52, 30, 1, -30, 18, -33, -8, -1, 15, -26, 2, -2, -9, 4, -24, -11, -45, -30, -13, 5, 3, 17, 0, 8, -37, -37, 2, 24, -1, -36, -16, 38, 9, -20, -9, -97, -77, 11, -8, 55, 11, 33, 7, 2, 15, -33, 13, 0, 28, 31, 15, -12, -52, 11, 37, 4, -20, -35, 19, 0, 12, 2, -2, -20, -11, -21, -6, 1, -6, 6, -20, 8, 9, 14, 26, 2, 1, -48, -3, 5, -21, 20, 0, -75, -43, 3, -6, 67, 32, 13, 12, 3, -54, 5, 3, -10, 28, -7, 6, -7, 39, -41, -7, 33, -27, 15, 18, 1, -15, 0, -28, -23, -35, 0, 4, -7, 10, -25, -46, 6, -17, -8, -27, -8, -1, -21, -25, 23, 14, -64, 3, 12, 9, -20, -11, 26, 26, 21, -15, -9, 13, 8, 39, 5, 14, 35, 18, 7, 5, 22, 16, 4, 14, 32, -5, 0, 29, -14, 16, -4, 8, -2, -5, -21, 22, -9, 22, -20, 3, 17, 8, 8, -18, -6, 7, -5, 25, 16, 0, -10, 8, -11, 13, 29, -18, 14, -8, -12, 23, -5, 21, 0, 16, 13, 22, -21, 29, 0, -30, 26, 27, 20, -3, 1, -1, -8, 11, 12, -9, -1, -5, -8, 11, 20, -3, -7, -3, -7, 7, -44, -3, -6, -16, -4, 15, 13, 10, 1, 0, -21, -11, 13, 12, 19, 3, -15, 14, 0, 16, -11, 9, 15, 17, -1, -1, 19, 22, 12, 10, 14, -7, -4, 7, -9, 17, -6, 7, 25, 11, -19, -3, -7, -5, -23, -2, 7, 29, -14, -29, 12, -1, 1, 9, -7, 5, -4, 16, -23, 0, 16, 11, 13, -42, -14, 11, 7, 15, -18, 18, -2, 15, 24, 23, -28, -8, 34, 25, 33, -3, 5, -18, -13, 7, 20, -9, 22, -9, -15, 2, -9, 14, 5, -14, 5, -7, -1, 14, -11, -5, 19, 36, 0, -5, 2, -11, 20, -26, -14, 13, -27, 13, 24, -18, 6, -29, 8, -1, -19, -50, -1, -45, -19, -5, -25, -15, -21, 19, 10, -8, 17, 4, -5, 3, 10, 2, 11, -19, 12, 0, 16, 10, -42, 3, 11, 25, 13, -1, 8, -21, -14, 1, 12, -1, 20, -7, -27, 3, -5, 21, 29, -4, -4, -12, 1, 1, -23, -25, -18, -14, 2, -18, -15, -22, -25, 10, 0, 2, 25, -12, -11, 6, -5, 4, 23, -25, -15, 7, 12, 3, -6, -19, 2, 10, 8, -6, -17, -6, -3, 9, 11, -11, 31, 11, -16, 3, -1, 27, 19, -14, 4, -21, 2, -18, -6, -13, -3, -15, -8, -10, -19, 12, -28, 1, 5, 2, 12, -6, 0, 12, -12, -11, 24, 0, 3, -4, 7, 5, -1, -23, 8, 0, -1, 8, -10, 2, -6, 7, 15, -5, 20, -11, -9, -27, -14, 9, 28, -14, -20, -7, 15, -17, -22, -33, 1, -17, 9, -15, -16, 4, -6, 16, -9, 0, 25, -5, 20, -2, -12, -9, 18, 8, 20, 5, 5, 3, 0, -13, -17, 8, 0, -10, 5, 0, -7, 18, -10, -14, 4, 1, 17, 19, 15, 7, -2, 10, 25, 1, 7, -14, -9, 39, 51, 31, -7, -4, -11, -27, 10, -4, 18, -11, 2, -1, -52, -22, -1, -9, -7, -7, 11, -18, -1, -1, -11, -7, -24, -5, -9, 8, -9, -12, -21, 13, -22, 5, -22, 24, 36, 19, 12, 7, -8, 31, -2, 31, -6, 21, -5, 27, 7, 8, 10, -23, 13, -9, -19, 15, 11, -26, -4, -6, -17, -34, -56, -11, 12, -40, -3, -20, 6, -2, -1, -31, -2, 11, -36, -11, 10, 8, -16, -9, 7, -16, -9, -27, 5, 27, -3, 7, 6, -12, 5, -13, 6, 21, 4, -1, 21, 10, 7, 20, 16, 21, 5, 6, 8, -14, 7, 4, -15, 7, 8, 0, 3, 10, -1, -12, 10, -7, -20, -4, -22, 12, -14, -6, 4, 2, -12, -15, -17, 26, 23, 17, -6, -42, 34, 8, 14, 10, -82, 23, 6, 5, 34, 36, 26, -29, -31, 6, 64, 32, 26, -2, -21, 1, -8, 18, -5, 12, 30, 10, -16, 27, -18, -24, -33, -32, -18, 25, -36, -14, -12, -55, -26, 19, -30, -3, -20, 25, 1, -11, 10, 4, 11, -3, 4, 8, 27, 32, 18, 47, 33, 26, 28, -21, 18, 39, -24, 11, 46, -9, -8, 12, 15, 16, -8, -30, -8, -30, -2, 48, -23, 13, 7, 14, 41, -2, 1, -21, -30, 24, -24, 52, -5, 10, -10, 5, 15, 17, -8, -45, 8, -16, 0, 24, -2, 28, 16, 6, 0, 18, 5, 31, -52, -27, 11, 17, 31, 12, -47, -12, 7, 1, -5, 3, -16, 5, 0, 7, 10, 9, -6, -3, 6, -10, -56, -13, -4, -31, -20, 31, 11, 0, -17, 8, 1, 8, -18, -15, -20, -35, 1, 7, 14, 0, 2, -11, 13, 6, -6, 3, 9, -3, -2, 13, 3, -17, -38, 0, 1, 6, 4, -6, 22, 7, 14, -9, -3, 22, 10, -16, -6, -13, 18, -8, -1, 33, -12, 3, 24, 15, -15, -21, 3, 30, 6, 8, -1, -38, -11, 30, 6, 9, 3, -23, 6, -8, 3, 50, -24, -6, 1, 53, 24, 9, 1, -2, 3, 24, -7, -52, -31, -5, 15, 15, 23, 34, 2, -16, -18, -22, 15, 30, -57, 0, 14, 46, 35, 11, 23, -3, -9, -25, 1, 5, 32, -27, -22, 19, -23, -10, -1, -68, 1, 1, -42, 20, -16, 23, -9, 1, 28, -64, 16, 23, -26, -18, 0, 18, 12, 4, -14, -13, 4, 17, 3, -26, -12, 16, -10, -2, 9, 23, -29, 14, 6, -14, 2, -28, -9, -24, 16, 1, -25, 28, -31, -10, 23, 7, -44, 11, 5, 3, 32, 14, -3, 10, -1, -42, -19, 24, 5, 12, -16, 14, 6, -5, 10, -9, -16, 8, 6, 24, -26, -29, 17, 9, 57, 17, -23, -15, 18, 8, -9, -13, 1, 25, -10, -1, 28, 19, 19, 1, -11, 29, -14, -12, -29, 20, -31, -24, 1, 9, 15, -8, 8, 31, 11, -4, 15, -8, -18, 22, -13, -6, -11, -6, -29, 2, 12, -27, 0, 8, 19, 0, -24, 23, 9, -14, 7, -14, -15, -26, -35, 15, -35, 16, -14, -5, 32, 4, -20, 24, 38, -18, 7, 19, 17, 38, 8, 20, -1, 28, -32, -33, -14, -14, 24, -13, -1, -24, 20, 24, -10, 29, -17, -3, -36, 30, 12, 21, 27, -28, 29, 7, -8, 14, 30, -26, -1, -10, -28, -7, 3, -31, -33, 14, -22, 32, 12, -33, -6, -33, -2, -3, -24, -6, 46, -13, 1, 5, -17, -14, -49, 17, 3, -22, 7, 2, -14, 15, 13, -1, -3, -30, 0, -7, 2, -12, 6, -19, -1, 19, 19, 17, 15, -55, -16, -3, -8, 18, -11, 24, -12, 8, -20, 14, 6, -8, -10, 3, -17, -5, -17, 0, 17, 3, 14, -13, -10, 12, 17, 29, 0, 5, -1, -2, 14, -4, 3, -16, -3, -28, -10, -6, 12, 23, 15, -15, 20, -2, 11, 16, -8, -20, 2, 8, 16, 13, 9, -2, 7, 18, 8, 5, 9, -18, 12, 3, 3, -18, -5, 20, 6, -2, -14, 0, 12, 43, 43, 4, 5, 0, -4, 5, -4, 32, -16, 16, -10, 0, 24, 11, -10, -9, 6, -5, -3, -12, 16, 28, 10, 15, -14, -16, 30, 5, 8, 11, -17, -34, 12, -17, 8, 17, -6, 21, 12, -14, 25, -8, 5, -17, 17, -7, 1, 5, -5, -8, -2, 64, -4, 11, 25, 22, 7, 7, -7, 7, -6, 50, -3, 15, 8, 35, 9, 0, 12, -4, -2, 26, 20, 16, -23, -21, 14, 7, 9, 3, 26, -17, 12, -17, -52, -22, 26, -27, 1, -54, -38, -35, -29, -29, 19, 25, -27, 4, 15, -31, 10, -38, 13, 3, 4, 4, 20, -36, -16, 18, 1, -34, -22, -32, 14, -44, 22, -7, -46, 3, 16, 5, -3, -26, 4, 5, 16, 14, -2, -18, -2, -4, 4, -1, -3, 5, 21, -3, -29, -23, -18, -24, 1, -23, -4, -16, 32, 25, 3, -15, 2, -12, 4, -15, 18, 16, -8, 20, -14, -14, -26, 4, 24, -33, -8, -9, 26, -26, 15, 8, -34, -11, 14, 21, 3, 8, 7, -19, 4, -1, -9, -8, 12, -20, 10, 3, -3, 14, -3, -8, 8, -31, -16, -14, -9, -1, 9, -20, -1, 22, -5, 11, 5, 6, 17, -61, 8, -31, 7, 3, 10, -2, -10, -38, 18, 9, 15, -8, -18, -24, -4, 0, 13, 29, 21, 19, 10, 2, -6, -26, 10, 6, 7, -6, 22, 12, 5, 16, -31, -58, -16, 17, 22, -11, 17, 1, 9, 2, -17, -9, 12, -10, 10, -30, 4, -12, -13, -12, 11, -7, 10, 23, 13, -22, 8, -15, 1, -34, 4, 38, 37, -9, 22, 1, -5, 10, -34, -30, 20, -9, 12, -19, -4, 23, -3, -54, 10, 13, -48, -14, 0, -9, 6, -26, 22, 21, -11, -17, 6, -82, 19, 23, -17, -6, -31, -21, -2, 19, -3, -10, -20, -2, 22, 13, 8, -36, -3, -25, 18, 15, -2, 1, -7, 19, 3, -7, -5, 16, 18, -11, 18, 1, -13, 21, -18, -38, -15, -1, 19, 22, 5, 2, -18, -17, 7, -6, 15, 16, 19, 10, -13, -11, -20, 17, 12, 11, 6, 1, 32, 2, 5, -1, -4, -9, 7, 9, 23, 20, -2, -5, -10, 35, -17, -7, -6, 11, 0, -3, 23, 22, -9, 36, -1, -3, -9, 8, -11, 11, 8, -16, 6, -19, 11, -4, 1, -19, 18, -112, 4, -13, -14, 3, 3, 10, -32, -6, 13, -4, 12, 0, -11, 0, 13, 13, -5, 20, 1, 31, 4, 21, 4, -4, 4, 34, 19, 26, 22, 27, -10, 38, 26, -24, 32, 23, 9, 3, 7, 15, -7, 9, 32, 10, -1, 24, 5, -20, 6, -8, -3, 7, 8, 6, 19, 17, 13, 13, 5, -21, 3, 31, -13, -25, -28, -2, -11, 15, 6, -15, 11, -14, 7, 11, -16, 25, 3, 1, 22, -7, -22, 47, 45, 10, 15, -18, 1, -29, -44, -22, -8, -28, -6, 8, -38, 3, 6, 18, 35, -30, -5, -36, 21, -9, 9, -21, 3, -24, 12, 20, -5, 14, 11, 10, 8, 10, -6, 15, 26, 5, 0, -5, -5, 6, 20, 22, 7, -19, 36, 75, 35, 8, 8, -9, 5, -27, 2, -14, -4, 5, -6, -39, -35, 2, 14, -9, 13, -30, 11, -25, 12, 10, 0, -21, 9, -16, 26, 18, 5, -32, 7, 12, 15, 13, -2, 1, 15, 16, 0, 18, 14, 22, -2, 2, 18, -17, 4, 22, -4, 15, 31, -4, -3, 15, -8, -17, -16, -32, 9, -20, 1, 39, 1, -5, 6, 4, 26, -14, 16, 8, -1, -25, 13, -10, 36, 24, 9, 9, -1, 15, 10, 5, 2, 2, -1, 28, -2, 0, 6, 8, -6, 20, 48, -29, 14, -44, 13, 1, 13, 28, 8, 19, -17, -13, -24, -31, 0, -6, 9, 13, 14, -9, -10, -3, 26, -24, 9, -4, 5, -43, -7, -12}

#define TENSOR_CONV2D_5_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_5_BIAS_0 {24, -21, 7, 69, -7, -19, 10, -91, 114, -15, 2, -112, -2, 44, -2, -19}

#define TENSOR_CONV2D_5_BIAS_0_DEC_BITS {8}

#define CONV2D_5_BIAS_LSHIFT {2}

#define CONV2D_5_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_6_KERNEL_0 {-40, 3, 36, 14, -32, 24, 52, 54, -7, -4, 10, 13, 13, 26, 19, -42, -30, -35, 13, 2, 18, 3, 49, 40, -5, -64, -2, -50, -17, 4, -9, 10, -14, -11, 41, 16, 48, 4, 5, -20, 18, -22, -3, -27, 2, -16, 34, -24, -8, 15, -22, -7, -25, 42, -36, -11, 5, 13, 60, 21, 38, 9, -7, 1, -14, -31, 36, 30, 10, 8, -38, 41, 7, 21, -20, -57, 13, -46, -30, -21, 26, -20, 18, 8, 43, -26, -77, -3, 15, 2, 21, -27, 19, -17, -64, -39, 7, 21, 22, -8, 6, -2, -1, 18, 16, 15, 23, 2, 47, -9, -22, 42, 78, 21, 17, -3, 1, 23, 21, -30, -18, -11, 3, 28, 4, 21, 19, 50, -19, 17, -4, -14, 14, 7, -19, 41, -6, 47, -6, 5, 5, -35, -20, 22, 9, 21, 46, 13, 17, 20, 4, 20, -1, -11, -16, 54, 18, 2, -12, -6, 27, 38, -15, 5, 47, 9, -14, 1, -34, -14, 17, -3, -3, -20, -22, 15, -39, 48, 8, 13, 30, 22, -34, 34, -23, 24, 19, -17, 19, -30, -20, 16, -56, -30, 27, -13, 19, 39, -1, -25, -16, -31, -20, 18, -8, 26, 24, -21, 9, -19, 26, 6, 47, 13, -5, 14, 18, -22, -48, -84, -6, 0, 4, 22, -39, -39, 10, 21, -10, 22, 71, 4, -68, -18, 16, 38, -17, -32, 5, -17, -36, -34, -3, -12, -11, 22, 27, 4, -50, -12, -33, 35, 2, 16, 13, 5, -29, 2, -3, -12, -36, -1, 31, 10, -84, -5, 24, 27, -17, -15, 12, 9, -43, -46, 12, -40, -2, 9, 7, 10, -60, 36, -8, 46, -10, -8, 23, 0, 11, 27, -8, 31, -17, -48, -30, -75, 35, -11, -18, -49, 6, 19, -37, 8, 20, 24, 10, 15, 9, -33, -48, -36, 33, -31, -29, -11, -16, -1, -48, -26, 26, 69, 10, -82, -8, 25, -46, 24, -41, 41, 14, 29, -25, -38, -12, -20, 17, 14, -6, -20, -2, -15, -8, -11, -62, 36, -5, 50, -2, 5, 18, -20, 51, 38, -22, -59, 0, 14, -45, 32, -36, 42, 7, 21, 19, -79, -20, -16, 3, -16, -2, -77, -8, 16, -43, 13, -43, 45, 13, -13, -13, -12, -3, -4}

#define TENSOR_CONV2D_6_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_6_BIAS_0 {5, 11, 7, -7, -7, -17, 10, -17, -20, 9, -14, -22}

#define TENSOR_CONV2D_6_BIAS_0_DEC_BITS {6}

#define CONV2D_6_BIAS_LSHIFT {0}

#define CONV2D_6_OUTPUT_RSHIFT {6}

#define TENSOR_CONV2D_7_KERNEL_0 {20, -59, 12, 23, 10, -30, 19, -71, -61, 16, 34, 24, -28, 25, -77, -22, -35, 0, -15, -43, -27, -63, 15, 18, -23, -40, 51, 25, 33, -27, -21, 26, 36, -7, -8, -32, 20, -10, -4, -14, -35, -40, 16, 31, 24, 16, -113, -35, -76, -31, 26, -28, 34, -1, -45, 14, -7, 24, -8, -31, -37, -17, 16, -9, 35, -60, 22, -14, -3, 13, -17, -18, 12, -39, 6, 7, 13, 22, -59, 26, 20, 16, 81, 59, -20, 4, -13, -7, -18, 23, -6, 9, 38, 48, 32, 49, 12, -15, -8, 4, 27, 3, -42, -30, 8, 21, 76, 45, -37, 4, -14, -9, 0, 2, -10, 33, 31, 33, 33, 35, 35, -31, -73, -65, -26, -5, 29, -30, -9, -8, -5, -9, 9, 4, 37, -34, 20, -27, 4, 36, -8, -9, -2, 3, -1, -8, -82, -25, 3, 27, 20, -19, 36, 1, 53, 74, 5, -20, -5, 11, -5, -22, 11, 7, 70, 8, 75, 71, 17, 13, 31, -54, -10, -86, -6, -59, -40, -34, -10, -30, -44, 28, 3, 3, -45, -84, -29, -61, -26, -7, 7, -121}

#define TENSOR_CONV2D_7_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_7_BIAS_0 {-7, -11, -3, -21, -21, 6, 9, 6}

#define TENSOR_CONV2D_7_BIAS_0_DEC_BITS {6}

#define CONV2D_7_BIAS_LSHIFT {0}

#define CONV2D_7_OUTPUT_RSHIFT {8}

#define TENSOR_DENSE_1_KERNEL_0 {9, -8, -24, -10, 5, -14, -12, 10, 0, 9, 6, 5, 4, -1, -6, -20, 8, 7, 4, 3, -7, -23, -2, -3, -12, 4, -19, -18, 6, 5, 7, 3, -55, -88, 16, 0, 1, -24, -37, -43, -19, -13, -22, -15, -16, 6, -4, 7}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_1_BIAS_0 {-22, -12, -6, 5, 19, 9}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {4}

#define DENSE_1_BIAS_LSHIFT {0}

#define DENSE_1_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_4_INPUT_OUTPUT_DEC 7
#define CONV2D_4_INPUT_OUTPUT_OFFSET 0
#define CONV2D_4_OUTPUT_DEC 4
#define CONV2D_4_OUTPUT_OFFSET 0
#define RE_LU_4_OUTPUT_DEC 4
#define RE_LU_4_OUTPUT_OFFSET 0
#define CONV2D_5_OUTPUT_DEC 1
#define CONV2D_5_OUTPUT_OFFSET 0
#define RE_LU_5_OUTPUT_DEC 1
#define RE_LU_5_OUTPUT_OFFSET 0
#define CONV2D_6_OUTPUT_DEC 1
#define CONV2D_6_OUTPUT_OFFSET 0
#define RE_LU_6_OUTPUT_DEC 1
#define RE_LU_6_OUTPUT_OFFSET 0
#define CONV2D_7_OUTPUT_DEC -1
#define CONV2D_7_OUTPUT_OFFSET 0
#define RE_LU_7_OUTPUT_DEC -1
#define RE_LU_7_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_DEC -1
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_OFFSET 0
#define FLATTEN_1_OUTPUT_DEC -1
#define FLATTEN_1_OUTPUT_OFFSET 0
#define DROPOUT_1_OUTPUT_DEC -1
#define DROPOUT_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC -2
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3, 1};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {7};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};

const nnom_io_config_t conv2d_4_input_config = {
    .super = {.name = "conv2d_4_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_4_kernel_0_data[] = TENSOR_CONV2D_4_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_4_kernel_0_dim[] = {6, 2, 1, 24};
const nnom_qformat_param_t tensor_conv2d_4_kernel_0_dec[] = TENSOR_CONV2D_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_4_kernel_0 = {
    .p_data = (void*)tensor_conv2d_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_4_bias_0_data[] = TENSOR_CONV2D_4_BIAS_0;

const nnom_shape_data_t tensor_conv2d_4_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv2d_4_bias_0_dec[] = TENSOR_CONV2D_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_4_bias_0 = {
    .p_data = (void*)tensor_conv2d_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_4_output_shift[] = CONV2D_4_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_4_bias_shift[] = CONV2D_4_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_4_config = {
    .super = {.name = "conv2d_4"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_4_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_4_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_4_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_4_bias_shift, 
    .filter_size = 24,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_5_kernel_0_data[] = TENSOR_CONV2D_5_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_5_kernel_0_dim[] = {4, 2, 24, 16};
const nnom_qformat_param_t tensor_conv2d_5_kernel_0_dec[] = TENSOR_CONV2D_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_5_kernel_0 = {
    .p_data = (void*)tensor_conv2d_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_5_bias_0_data[] = TENSOR_CONV2D_5_BIAS_0;

const nnom_shape_data_t tensor_conv2d_5_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_5_bias_0_dec[] = TENSOR_CONV2D_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_5_bias_0 = {
    .p_data = (void*)tensor_conv2d_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_5_output_shift[] = CONV2D_5_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_5_bias_shift[] = CONV2D_5_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_5_config = {
    .super = {.name = "conv2d_5"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_5_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_5_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_5_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_5_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_6_kernel_0_data[] = TENSOR_CONV2D_6_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_6_kernel_0_dim[] = {2, 1, 16, 12};
const nnom_qformat_param_t tensor_conv2d_6_kernel_0_dec[] = TENSOR_CONV2D_6_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_6_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_6_kernel_0 = {
    .p_data = (void*)tensor_conv2d_6_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_6_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_6_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_6_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_6_bias_0_data[] = TENSOR_CONV2D_6_BIAS_0;

const nnom_shape_data_t tensor_conv2d_6_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_6_bias_0_dec[] = TENSOR_CONV2D_6_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_6_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_6_bias_0 = {
    .p_data = (void*)tensor_conv2d_6_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_6_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_6_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_6_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_6_output_shift[] = CONV2D_6_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_6_bias_shift[] = CONV2D_6_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_6_config = {
    .super = {.name = "conv2d_6"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_6_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_6_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_6_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_6_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_7_kernel_0_data[] = TENSOR_CONV2D_7_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_7_kernel_0_dim[] = {2, 1, 12, 8};
const nnom_qformat_param_t tensor_conv2d_7_kernel_0_dec[] = TENSOR_CONV2D_7_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_7_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_7_kernel_0 = {
    .p_data = (void*)tensor_conv2d_7_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_7_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_7_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_7_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_7_bias_0_data[] = TENSOR_CONV2D_7_BIAS_0;

const nnom_shape_data_t tensor_conv2d_7_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_7_bias_0_dec[] = TENSOR_CONV2D_7_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_7_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_7_bias_0 = {
    .p_data = (void*)tensor_conv2d_7_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_7_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_7_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_7_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_7_output_shift[] = CONV2D_7_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_7_bias_shift[] = CONV2D_7_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_7_config = {
    .super = {.name = "conv2d_7"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_7_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_7_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_7_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_7_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_1_config = {
    .super = {.name = "global_max_pooling2d_1"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_1_config = {
    .super = {.name = "flatten_1"}
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_1_kernel_0_dec[] = TENSOR_DENSE_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_kernel_0 = {
    .p_data = (void*)tensor_dense_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_1_bias_0_data[] = TENSOR_DENSE_1_BIAS_0;

const nnom_shape_data_t tensor_dense_1_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_1_bias_0_dec[] = TENSOR_DENSE_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_1_bias_0 = {
    .p_data = (void*)tensor_dense_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_1_output_shift[] = DENSE_1_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_1_bias_shift[] = DENSE_1_BIAS_LSHIFT;
const nnom_dense_config_t dense_1_config = {
    .super = {.name = "dense_1"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_1_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_1_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_1_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_1_bias_shift
};

const nnom_softmax_config_t softmax_1_config = {
    .super = {.name = "softmax_1"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_1_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_io_config_t output0_config = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create(nnom_status_t *state)
{
	static nnom_model_t model;
	nnom_layer_t* layer[14];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_4_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_4_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_5_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_6_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_7_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_1_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_1_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_1_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_1_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_22_NNOM_H