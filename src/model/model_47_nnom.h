#ifndef MODEL_47_NNOM_H
#define MODEL_47_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_47_nnom
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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_8_KERNEL_0 {17, 66, -29, 60, -35, 7, 1, 2, -35, -21, -65, -74, 59, -47, -33, -41, -4, 15, 20, -11, -3, -5, -63, 54, -35, 30, -29, -24, -6, -48, -49, -3, 9, 31, -53, 87, -79, 29, -30, 15, -55, -44, -14, 29, -3, -10, 45, 0, 57, -7, 18, -64, -18, -43, -61, -35, -46, -27, -53, -33, 62, 7, 52, -13, 34, -8, 63, 47, -8, -22, -23, 21, 38, -46, -16, 1, -26, 48, 49, -24, 48, -6, -41, -41, -80, 0, -5, 33, 48, -37, 25, -15, -43, 39, -13, 2, 29, 8, 43, 67, 14, 12, 11, -14, -24, 29, 36, -76, -63, 10, 36, 7, 14, 24, -49, 3, -24, 23, 61, 24, 3, 21, -5, -25, -6, 43, -30, 47, -52, -32, -23, -42, 18, 96, -16, -1, 5, -30, -10, -75, 18, -4, -1, 79, 39, -91, 31, -41, 9, 25, -28, 22, -12, 28, 11, -34, 7, -44, -18, -27, -38, -38, -16, 52, 40, 41, 40, -16, 52, -12, 47, 16, -37, 51, -9, 71, -31, -37, 17, 78, 38, -15, 26, 100, -23, -58, -8, 30, 19, -5, -26, -58, 25, -12, -27, -56, 9, -34, -30, -29, -2, -25, -37, -39, -24, 10, -36, -5, 44, -19, 78, 0, 97, -7, 72, -1, 0, -32, 54, -12, 68, 29, -58, -7, -68, -31, 35, -7, 37, 5, -12, 66, 18, -88, -40, 13, -1, 21, 29, -26}

#define TENSOR_CONV2D_8_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_8_BIAS_0 {-18, -13, -9, 4, -43, 4, -34, -40, -5, -70, 1, -12, -1, -19, -47, -65, -7, -11, -36, -36}

#define TENSOR_CONV2D_8_BIAS_0_DEC_BITS {8}

#define CONV2D_8_BIAS_LSHIFT {7}

#define CONV2D_8_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_9_KERNEL_0 {6, 3, -12, 15, 25, 15, -21, 4, -8, 16, -14, 3, -70, -1, 21, 30, -3, -2, -2, 6, 15, 11, 1, -36, -2, 1, -4, -21, 31, -4, -40, 28, -28, 8, 34, 26, 11, -16, -56, 9, -35, -1, -17, 1, 16, 0, 1, -7, 30, 2, 5, -31, 5, 24, 5, 9, 5, -13, -8, 16, 3, 11, 18, -16, -24, -11, -27, 8, -3, 50, 5, -25, -22, -43, -38, -17, 7, -22, -3, -2, -37, -10, 4, 20, -19, 26, -7, 27, -31, 42, -34, -19, -21, -57, 25, -8, -17, 4, 8, 27, -17, 7, -6, 5, -40, 8, 2, 6, 1, 15, 9, -23, -23, 5, 11, 27, -41, -5, 15, 20, -1, 9, -19, -1, -2, -41, -10, 1, 11, 16, -14, -1, -31, 2, 24, 14, 0, -14, -30, 6, 8, 14, 24, 5, -35, -7, 10, -23, 2, 32, -12, 32, 5, 6, -10, 7, -10, -29, 13, 29, 11, 6, 18, 13, -11, 6, 12, 0, -11, 7, -4, -9, 28, -22, -12, 18, 3, -5, -11, -32, -9, -15, 20, 11, -40, -10, 7, -3, -8, 31, 6, 4, 10, -7, 16, -9, -29, 15, 11, -15, 14, -1, -1, 0, 0, 4, -26, -19, 8, -58, -2, -2, 5, -11, -36, -27, -16, 4, -15, -9, -7, 3, 1, 2, 4, 2, 30, 13, -5, -25, -20, 14, 27, 12, -15, 16, -4, 12, -46, -8, 5, -13, 4, 9, 30, 16, 23, -8, 7, 31, 2, -9, -8, 2, 12, -1, 7, 12, 21, -6, 25, -2, 18, -4, 9, 8, 8, -5, 4, 12, -2, 31, 19, 3, -20, 29, -11, -3, -4, -3, -1, -21, -19, 6, -4, -2, -10, -49, 24, 5, 10, -7, 10, -5, 21, -26, -3, -6, 13, 32, 7, -5, -12, -32, 8, 2, -13, 9, -11, -8, 4, 5, 5, -23, 27, 10, -4, 1, 1, -11, -6, -22, 9, 18, -27, 22, 7, 8, -10, 15, 13, -3, 13, 14, 12, 49, 5, -13, 7, 17, 22, 25, -6, -3, -31, -26, 4, 36, 3, 0, 6, -6, -9, -4, -2, 23, -19, 11, 7, 15, -16, 2, -1, -7, -36, 14, 11, -3, 5, 16, -7, -7, 12, -6, 3, 21, 3, -15, -6, 20, -4, -2, 7, 11, -25, -19, -9, 25, 14, 16, 2, -29, -8, -9, -5, -2, -4, 1, -7, -27, 1, -28, -1, -7, 4, 11, 12, -7, 22, 11, 12, 5, 2, 14, -4, 5, 1, -13, -24, 12, -4, -7, -28, -15, -48, 0, 3, 7, 14, 21, -20, -17, 3, -10, 3, 2, 9, -13, -11, 2, 5, -29, -15, 13, 17, 13, 15, 0, 17, 42, 21, -3, 10, 8, -22, 6, 8, -13, -5, -3, 21, 15, 1, -14, -13, 7, 8, 19, -22, 12, -21, -18, -11, -9, 14, 8, 13, -21, 14, -1, -12, 9, -15, -8, 14, 10, 31, -1, 6, -2, -6, -14, 15, 7, 15, 29, -7, -24, -2, 17, 30, 2, 5, 1, -11, -23, -5, 19, 17, 8, 7, -2, -14, 3, -9, 30, -3, -2, 1, -3, -6, -23, 8, 8, 13, -7, 7, 1, 7, 27, -8, 3, -4, 2, 9, 24, 6, -5, 0, 4, 12, 9, 7, -16, -9, -1, 4, 14, -5, -2, -6, 9, 16, 12, 14, 1, 3, -9, -7, 21, 4, -5, -11, -3, 7, 9, 13, 32, 9, 33, 8, -10, 12, 21, 14, 11, 4, -9, 29, 20, 9, 8, -6, -4, 1, 1, -7, 4, -5, 22, 0, 2, 1, -2, 17, -7, 5, -10, 3, 2, -2, 5, -7, 1, -15, 12, 10, -2, 20, 12, 8, -4, -1, 9, -9, 17, -7, -2, 8, 13, -2, 14, 13, 6, 1, -8, 0, 5, 4, 37, 5, 5, -6, 3, 20, 4, 7, -10, 4, -1, -16, 13, -4, 4, 2, -26, 22, 31, 4, 39, 8, -4, 10, -15, -2, 2, -13, -7, 9, 10, -19, -1, 1, 13, 10, -13, -21, 1, 18, -3, 21, -12, 0, -5, 21, -2, -7, 1, 1, 15, 0, -14, 11, -10, -6, -22, 2, 1, 6, 15, -2, 3, 7, -1, -12, 6, -9, -13, 1, -4, -37, -6, -11, 1, 8, -22, -3, 19, -17, -50, -7, 15, 3, 4, 10, 10, -18, 4, 4, 1, 6, 16, 6, 3, -17, 15, 32, -7, -6, 26, 8, 7, 2, 6, -25, -6, -2, -16, 23, -13, 12, -10, 21, 18, 6, 7, 0, 8, 7, -5, 14, 30, 1, 0, 23, -32, -17, 8, 4, 11, 9, 22, 3, -12, -17, -30, 1, -1, -13, 5, 11, 8, 6, -23, -10, -39, -12, -4, 33, -11, -16, -11, -9, 9, 23, 6, 3, 13, 10, 27, 14, 1, 5, 8, 1, 5, -1, 1, 1, 13, -4, -34, -71, 9, -15, -9, 15, 40, -10, 23, 7, 14, 26, 24, -14, -8, -13, -2, -5, -12, 2, 10, -6, -18, -17, -8, -7, 37, 9, -2, 8, -13, 0, -38, 13, 21, -12, -44, 14, -15, -5, 2, -10, -12, -39, -27, 2, -22, -8, 16, -33, -5, -5, 54, 20, 15, -25, 12, -9, -8, -3, -20, -14, -1, 1, 13, 8, 0, 1, -22, -3, 6, 0, 3, -9, 20, 15, -7, 2, 12, -35, -22, 1, 2, -6, -15, 26, 6, -24, -9, -12, 12, -30, 33, 13, 24, -14, -10, -6, 24, -33, -13, -5, 9, -41, -20, 4, -28, 9, 6, -2, -29, -2, 8, -43, -32, 2, -26, 0, 40, -1, -1, -2, 3, -5, 9, -4, 21, 0, 26, 13, -33, -19, 16, 0, 3, 4, -69, 39, 25, 2, 13, -10, -16, -11, 5, 19, -55, -38, -31, -2, -8, -13, 2, -14, 14, 4, -9, 2, 54, -12, 15, -34, -5, -4, 1, 16, 4, -3, -33, -1, -25, 11, 2, 20, 17, 4, 4, 12, -8, 17, -1, -9, 3, -10, -8, -4, 11, -2, 4, 9, 37, 10, 1, 3, -26, -3, -1, -4, 7, 6, 20, -51, 12, -24, -5, 23, 14, 13, -45, -2, 3, 22, 24, 9, 5, -3, 12, 23, -9, -5, -14, 4, -5, -16, 2, -9, -1, -6, -2, 12, 33, 6, 13, 28, 0, -10, -3, 18, 9, 1, -14, -10, 11, -23, -6, -20, 19, -4, -4, -20, 5, -15, 10, -2, 21, -2, 17, 13, 12, 2, -8, 2, -3, -22, 3, 8, 1, 12, -24, 19, 8, -5, 18, -8, -9, 7, -7, 2, -2, -17, -5, -1, -5, 7, 0, -18, -17, -32, -64, -63, 0, -46, -2, -15, -15, -13, -3, -48, 47, -1, 9, 18, 11, -37, 4, -12, -39, -6, -19, 13, 23, 12, 9, -39, -1, 0, 1, -11, 28, -6, -18, -19, 8, -9, -10, -9, 30, -20, 35, 15, -28, 2, 15, 4, 26, -13, 23, -5, 0, -8, 5, -6, -15, 1, -8, -5, 22, 5, -3, 7, -22, -20, -5, 1, 24, -13, -20, 10, -2, 8, -8, 0, -9, -32, 4, -11, 18, 17, 27, -6, 6, 7, 8, -6, -7, -5, 6, 3, 19, -25, -6, -18, -19, 14, -9, -11, 14, -3, -8, 1, -3, 4, 4, -13, 32, -3, -25, -1, 2, 5, -1, 19, 9, 2, 12, 18, -3, -18, 25, 17, 3, -6, 15, -6, 26, 1, -24, 30, 10, 8, -20, 18, -1, 7, -23, -12, -1, 21, 20, -1, -19, -3, 2, 8, 9, 3, 7, 2, 6, 27, 19, 6, 1, 3, 6, 9, 15, 13, 27, 8, -9, 0, 10, 9, 9, 0, 13, 34, -13, -10, 10, -25, -5, 13, -8, 10, -43, 8, 3, -6, 3, 4, -15, 26, 17, 8, 13, 17, 6, 17, 20, 8, 20, 2, 16, 10, -5, 5, 46, 13, 1, 13, 25, -12, 37, 15, 3, -15, 16, 11, 13, -15, 32, -3, -9, 8, 4, 8, -4, -3, -11, -16, 5, 8, 4, -4, 3, -14, -2, -3, 11, -4, -15, 3, -8, 12, 4, -18, 7, 1, -3, 14, 2, -15, -30, 0, 12, -55, -10, -45, 2, 12, 17, 25, -28, 5, 2, 4, 12, -1, 1, -13, -13, -22, 21, 21, 3, 7, 8, -13, 0, 9, 4, -11, 8, 11, 1, 6, 34, 4, 3, 4, -7, -26, 19, -18, -4, -10, 8, -3, -1, -5, 3, -12, -16, -27, -7, 19, 13, -27, -24, -20, -3, 4, 16, -9, 6, -16, 12, 1, -5, 5, 18, -10, 8, -4, 20, -6, 31, 3, 2, -14, 2, -16, -16, 7, 0, 16, -2, -6, 24, -21, -6, 8, 3, 9, 28, -6, 10, -11, -13, -5, 7, -4, -9, -2, -2, 4, 12, 3, 20, -7, 26, 1, 6, -7, -75, 21, 20, -4, -9, 19, -31, 3, -10, 10, -2, -25, 0, -13, -4, 18, -22, -29, 4, -3, -14, 21, -24, -4, -14, -13, 1, -10, -18, 13, -2, -24, -54, 9, -4, 21, -4, 11, -4, -3, -19, -4, 52, -7, -3, -4, -23, 19, 18, -12, -12, -40, -60, 9, -8, -17, -10, -34, 4, -23, 5, 0, 7, -6, -19, -8, 5, -14, -18, 8, 6, -8, -18, -4, -26, 17, 10, -13, -3, -10, -1, -6, 3, 12, 2, 1, -5, -16, 24, -6, 5, -17, 2, -3, -5, -5, 22, 13, -4, -5, -30, -4, -51, 0, -5, -2, 3, 2, -35, 3, 9, -13, 12, 7, -12, -18, 4, -32, -3, -30, 22, 16, 39, 20, 1, 20, -4, 8, -18, 15, 17, 19, -36, 21, -7, 15, -14, 3, 12, 10, -16, 10, -50, 21, 3, -9, -11, 12, -17, 1, 7, -38, -10, 8, -19, 12, -6, 8, 2, 4, -15, 12, 14, 4, 15, -5, 0, 23, 14, -10, 13, 23, 7, -16, 6, -29, -2, 25, -2, -17, 3, -4, 8, -2, 0, 5, 12, 2, -2, 7, 4, 17, -15, 15, -14, 20, 8, 4, 4, 5, 14, -13, 23, 8, 8, 10, 23, -15, 3, 2, -3, 13, -1, 8, 9, -11, -1, 14, -10, 0, 9, -9, -3, 1, -2, 9, 2, 8, -2, 1, 4, 7, 8, 9, 4, 14, 14, 9, 0, 2, -12, 10, -3, -17, 8, 8, -6, -19, 6, -17, 14, 9, 12, -4, 0, -7, 7, 11, 3, -5, -1, -3, 23, -4, -28, -11, -3, 9, -6, -11, 21, 8, -1, 17, 9, 17, -5, 29, -11, 0, -10, 10, -7, -7, 13, 8, 2, 35, 1, -24, 6, -29, -9, -20, 3, -11, 6, 17, 3, 2, 5, -8, 19, -23, 3, -11, 11, 14, -1, 9, 17, 19, 5, 0, 0, 0, -4, 2, 1, -4, 1, -2, -4, -1, -1, -4, -1, -1, -2, -4, 1, 0, -2, -4, 2, -3, 1, -1, -4, 3, -3, -3, -2, -6, -1, -3, -2, -2, -3, -4, -3, -4, -3, 2, 4, 1, -3, -3, -4, 0, -2, -1, -2, 0, -3, 1, -3, -1, 1, -4, -2, 3, -4, -5, -1, -4, -2, 1, -3, 2, -2, 0, -5, 1, 1, -2, -7, -5, -2, -5, -4, -3, -2, 2, 0, -5, 0, 0, -3, 0, -1, -4, 2, 3, -3, -5, 1, -5, -1, -1, -2, -4, 3, 0, 0, 2, -4, 3, -4, -5, -3, 2, -4, -3, -5, -1, 2, -3, 0, -4, 2, 2, 4, -3, -4, -4, -2, -1, 2, 1, -2, -5, -1, -1, -1, 1, -2, 3, 2, 1, 3, 0, 3, -3, -1, -6, 2, 0, -4, -2, -2, -1, -3, -6, -1, 1, -2, -1, 3, -5, 1, -1, 4, 0, -15, 5, 21, 29, 22, -4, -14, 10, 3, -2, -5, 3, 4, 16, 27, -5, 27, 18, 0, 20, -1, 5, -20, -5, 7, -25, -10, 17, -14, 0, 8, 11, 1, 6, -30, 4, 7, 2, -28, 15, -1, -9, 0, 18, -7, -6, 10, 1, -37, 1, 5, 7, -8, 23, -34, 9, 33, 24, -13, 15, -7, -14, -3, -4, 8, -20, 9, -7, -7, -7, -1, 15, 3, 2, -23, -6, 13, 0, -8, 16, -13, 9, 7, 1, 9, 2, 12, 11, 13, -8, 1, 0, -8, -22, 4, -11, 20, 16, -13, 26, 12, 0, 5, -1, 10, -8, -30, 7, 18, -15, -24, 3, 2, 16, 0, 0, -12, -7, -8, 3, -12, 6, 19, 2, 6, 0, 3, -13, -18, -1, 3, 12, -6, -24, -19, -14, 26, 14, 7, 20, 3, -21, -24, 2, 5, 6, 4, 8, 0, 5, 12, 5, 2, 18, 1, 11, -2, -8, 8, -39, -2, 6, -29, -36, 3, -7, -25, 0, -12, 3, 1, 18, 0, -18, -37, 12, 2, -17, 3, -14, -9, 31, 6, -58, -8, 8, 13, -4, -12, -4, -36, -2, -12, -30, -1, -24, -10, -16, -1, 2, 9, -19, -1, -10, -31, 15, -16, -3, 23, 12, 11, 1, 9, 11, 35, -14, -3, 10, -6, 3, 13, -18, 7, -40, 4, -35, 1, -2, 9, -3, -1, 9, -11, -23, -21, 18, -19, -2, 2, -2, 0, -12, 22, -35, -32, 6, 11, 12, -17, -10, -4, 24, 26, -5, 24, -22, 3, 14, 11, -13, 8, 5, -11, -7, 8, 22, -1, -21, 3, 23, 22, 11, 4, 3, -4, -7, -12, 26, 4, 13, -31, -16, 17, 17, -26, -56, 28, -2, 43, -1, 8, -18, 1, 8, 20, -1, -13, 22, 4, 13, 17, 13, -18, 12, 1, 7, -25, 3, -11, -8, -28, -13, -4, -1, -20, -10, -14, -8, 2, 0, 2, -3, -5, -4, -2, -5, -5, 0, 0, -2, 0, 3, -4, -5, -3, -1, -5, -5, -4, -4, 3, -5, -2, -1, -4, -5, -1, -3, -3, 1, 1, -4, -1, -5, -3, -6, -6, -2, -4, -4, 3, 3, 1, 0, -1, -3, 0, -6, -5, -3, 0, 2, -2, -6, -2, 0, -1, -5, -2, -3, -1, 1, 2, 3, 1, 3, -4, 1, 2, -1, 0, 0, -4, -2, -3, -5, 1, -5, 3, 3, 2, -2, -1, 3, 1, -4, -1, -5, -2, -2, -1, -1, 0, -5, -2, -3, 2, 4, 1, 0, -5, 1, -1, -3, -3, 0, -3, 0, -3, -3, -4, -5, -3, 0, -4, -2, 0, 1, 2, -3, -2, -3, 3, 3, 0, 2, 3, -6, 4, -3, 2, -5, -4, 0, 2, -5, -5, -2, 3, 2, -3, -2, 0, 0, 0, 0, 1, -2, -3, 0, -2, 2, -4, -1, -1, 2, 1, -4, -5, 13, 1, 3, 26, 21, -20, -16, 16, -19, -26, -7, 11, -13, -16, 14, 36, 10, -9, -1, 19, 2, 41, 6, -22, -5, -3, -4, 12, 27, -2, 2, 15, 23, -2, -36, -5, 3, 3, 1, -23, -4, 20, 4, 24, -11, -1, 21, 21, -9, 6, 9, -12, -4, 1, -4, -4, -3, -20, 0, 9, 9, 20, 19, 6, 1, 4, 0, -7, -26, -13, -5, 22, -10, 25, -9, 13, -6, -4, 5, 25, -3, -5, 11, 14, -29, 11, 4, -6, -13, 25, -9, -3, -3, 14, 18, 26, -9, 4, 3, 17, -15, -10, -2, -9, -4, -15, -17, -6, 5, 9, 10, -3, -5, 0, -16, 2, -28, -13, -6, -2, -10, 20, 2, 6, -39, 16, 14, -12, 23, 14, 0, -3, 6, -6, -5, -33, 6, -18, 8, 23, 5, 2, 4, -17, -8, -4, 1, -12, 4, 4, 23, 47, 2, -2, 12, -6, 13, 5, -10, 7}

#define TENSOR_CONV2D_9_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_9_BIAS_0 {-29, -16, 2, -63, -56, 19, 12, -40, -46, 10, -88, -8, -73, 13, -7, -1}

#define TENSOR_CONV2D_9_BIAS_0_DEC_BITS {7}

#define CONV2D_9_BIAS_LSHIFT {5}

#define CONV2D_9_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_10_KERNEL_0 {-2, 23, -6, -66, 0, -48, -16, -26, 25, 6, -58, -2, -30, -40, 2, 19, -38, 35, -27, -30, 65, -117, -32, -43, -2, 46, 43, 12, 12, 4, 17, -20, -74, -10, -31, 55, 24, 18, 5, 6, 14, -13, 16, -16, 30, -7, -18, 13, 39, -33, 11, 24, 57, 22, 29, 29, 21, -19, 32, 8, 23, -45, 17, 14, 44, 57, 31, 11, 1, -33, 20, 18, 22, -41, -43, 17, -7, -53, 15, 26, -25, -22, 20, 5, 16, 34, -6, -56, -15, -11, -58, 9, -108, 48, -9, 26, -19, 16, 8, -14, 2, -29, 7, -34, 6, -8, -29, -3, -98, 25, -11, -71, -24, 57, -18, -4, -16, -3, 18, 0, 27, 20, 14, 17, 27, 44, 3, -12, -45, 28, -32, 47, 37, -33, 52, -28, 35, 25, -65, -4, -4, -52, -17, -4, -39, -18, -49, -37, -5, -28, -26, -25, 20, 15, 15, -1, -5, -20, 7, 30, 5, -14, -14, -8, -19, 8, 0, 10, -19, -19, -25, 13, 1, 6, 13, 1, 16, -14, -9, -4, -18, -21, -22, -10, 5, -9, -24, -12, -3, 5, -16, -23, -1, 1, -47, 15, -27, -84, 15, -10, -23, -73, -7, 10, -6, -2, 17, -3, 22, 31, -6, 12, 18, -5, -2, 35, -1, -10, 45, 10, 27, -55, 12, 7, -77, 9, 26, -103, -11, -40, 12, -63, -98, -6, -46, 12, -17, 11, 2, 12, 9, 38, -6, -77, 42, 19, 51, -88, -108, 24, -39, 8, 4, 11, -6, 45, 69, -36, -40, 16, 81, 30, 36, -29, -20, 19, -74, 6, -47, -15, 18, -31, 22, 12, -20, -22, 38, 22, 9, -9, -15, -3, -23, -5, -2, 41, 6, 16, 58, 22, 30, -21, 48, -35, -22, 9, 8, 1, 2, 18, 0, -15, -7, 3, 53, 26, 3, 14, 11, 20, 3, 41, 21, 5, 24, -9, 36, 20, 5, 18, -34, -2, -3, 31, 7, -49, -18, -36, 19, 54, 14, -8, -13, -4, -10, -8, -20, 20, 29, 49, 75, -51, 28, 40, 3, 7, 28, 22, 69, -12, 12, 24, 83, -42, -11, 0, 29, 22, 28, -10, 15, 43, -62, 5, -43, 11, -9, -5, -74, 0, -4, 20, -9, 62, 3, -17, -30, 26, 6, 0, -27, 40, -12, 13, 24, -3, -15, 8, 51, 66, -4, 27, 9, 18, 0, 4, -24, 25, 11, 58, -65, -20, 21, -51, -53, -22, 19, -27, -54, -1, -4, 8, -30, -51, 2, 47, 53, 10, 22, 4, 18, 9, -27, 30, 27, 22, 6, -13, -8, -29, 3, -7, 48, 13, 55, 4, 35, 38, -26, 6, 31, 19, -21, 10, 0, 7, 9, 10, -37, -38, -3, 8, -26, 32, 23, 27, -26, -23, -26, 12, -11, 57, -11, -20, -40, -57, -85, -29, 20, 69, 35, 6, -50, -11, 33, -12, 7, -20, 2, 25, -25, 36, -8, 19, 3, -38, 13, 6, 12, -32, -31, 10, -8, 39, 19, 3, -36, -28, -20, 17, -60, -2, 39, 3, 34, -58, -26, 14, -11, -8, 7, 33}

#define TENSOR_CONV2D_10_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_10_BIAS_0 {21, -107, 0, 11, 2, -25, -72, 2, 13, -67, -20, -13, -1, -31, 16, 22}

#define TENSOR_CONV2D_10_BIAS_0_DEC_BITS {7}

#define CONV2D_10_BIAS_LSHIFT {3}

#define CONV2D_10_OUTPUT_RSHIFT {6}

#define TENSOR_CONV2D_11_KERNEL_0 {6, -16, 11, -8, -33, -7, 6, 1, -63, -36, -11, -35, -20, -13, -31, -7, 11, -62, 0, 8, -1, -6, -13, 18, 2, -35, -3, 4, 7, -17, 23, 8, -12, -7, -13, -4, -12, -5, 3, -5, -9, 0, -10, 3, -11, -6, -13, 5, 1, -11, -6, 0, -1, 4, 6, 2, -5, -9, -1, -3, -8, -5, -7, -3, 4, -39, 0, 10, -16, 1, -28, 15, 1, -14, -17, 1, 1, -24, 19, 14, 17, -29, -5, -5, 10, -8, -8, -8, 3, -25, -19, 2, -3, -2, 0, -19, 25, 16, -59, -26, 5, 3, 6, -4, 2, -17, -14, 1, 21, -18, 9, 2, -12, -34, -20, 19, -41, 5, 17, -44, -12, -4, -1, -40, -5, 1, -27, -14, 19, -67, 12, 6, -8, 9, -9, 12, -6, 10, -12, -2, -5, -30, 13, 13, 14, -15, -14, -9, 4, 6, 6, -4, 12, -35, -34, 9, 0, 4, 7, -24, -6, 2, -2, 5, 0, 3, 0, -6, 15, 0, 1, 21, 5, 10, -20, -6, 3, 21, 13, -27, 8, 5, 16, 4, 13, 5, -13, -47, -7, -4, -4, 0, -1, 8, -33, 11, 17, 2, 11, -9, 6, -9, 5, 9, -15, -29, 9, -4, -12, -2, -64, -14, 10, -3, -49, 0, -9, -28, -12, 4, 16, -26, 2, 13, -16, -18, 14, -5, -17, -8, -5, 5, -51, -55, -20, -46, -4, -31, -3, -3, 11, -42, -13, 12, 7, 3, 0, 10, 11, -8, -19, 2, 6, -17, 21, 3, -3, -7, 1, -19, 11, 1, 8, 6, 0, 3, -1, -10, -1, -10, -2, 14, -2, 16, -16, -14, 2, 0, 1, -72, -1, 9, -6, -14, -3, 3, 0, -2, -32, -2, -59, 6, 5, 4, -3, -6, 6, -6, -30, 6, 16, -9, 11, -30, -54, 3, -54, 16, -49, 5, 0, -2, -10, 17, -3, -18, 3, -3, -1, -42, -15, 14, 13, 4, -38, 4, -4, -22, 1, -1, -9, 19, -64, 6, -4, -13, 19, -12, 13, 18, -14, -4, -28, 11, 0, -1, -22, 14, -2, -5, -8, -44, -3, -18, 8, -1, -13, 1, -10, 0, -63, -40, -13, -45, 0, -19, -11, -10, 1, -41, -11, 4, 5, 6, -20, 13, 5, -11, -21, -2, 2, -40, 25, 12, -48, 0, -25, -52, -34, 8, 22, -13, 1, -9, -1, 14, 18, 2, 1, -13, 7, 7, 11, -13, -4, 8, 15, -35, -4, 2, -16, 14, -4, 9, -23, -19, -65, -2, -6, -21, -14, -8, 13, -21, 4, -1, -1, 15, 9, -11, 5, -9, -2, -2, 13, 2, -44, 5, 17, -42, 4, 1, -8, 13, 5, 11, -51, -46, -6, -22, 5, -23, -10, -9, 20, -15, -14, -15, -2, -15, -53, -5, -39, 0, -14, 3, -54, 10, 8, 9, 8, 13, 10, -1, 8, 13, -9, -65, 13, 7, 1, -50, 8, -1, -4, -7, 7, -15, 11, -7, -8, 6, 4, 12, 19, -26, -22, 2, -32, 7, -30, -1, 0, -30, -27, -26, 1, -18, 12, 4, -37, -5}

#define TENSOR_CONV2D_11_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_11_BIAS_0 {-16, -23, -44, 29, -47, -65, -25, -14, -85, 45, -26, -4, 13, 7, 23, 24}

#define TENSOR_CONV2D_11_BIAS_0_DEC_BITS {7}

#define CONV2D_11_BIAS_LSHIFT {2}

#define CONV2D_11_OUTPUT_RSHIFT {7}

#define TENSOR_DENSE_2_KERNEL_0 {-45, -41, -36, -31, 0, -2, -1, -1, -11, -8, -28, 10, -11, -9, 4, 8, -28, -24, -13, 13, 16, 13, 9, 5, -5, -8, -44, -38, -19, -48, 7, 4, 0, -4, 11, -7, -36, -55, 5, 8, -18, 15, -40, -36, 12, -25, 10, 8, 4, -3, -22, 7, -4, -38, 0, -7, 6, -1, 14, -14, -2, -32, 13, -11, -83, 5, -60, -99, -74, -47, -91, -74, -57, 6, -63, -79, -55, -49, -83, -75, 4, 1, 2, -46, 16, -14, -1, 11, -32, -32, -34, 14, -51, -46, 7, -34}

#define TENSOR_DENSE_2_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_2_BIAS_0 {-21, -1, -54, 2, 89, -2}

#define TENSOR_DENSE_2_BIAS_0_DEC_BITS {5}

#define DENSE_2_BIAS_LSHIFT {2}

#define DENSE_2_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define CONV2D_8_INPUT_OUTPUT_DEC 9
#define CONV2D_8_INPUT_OUTPUT_OFFSET 0
#define CONV2D_8_OUTPUT_DEC 7
#define CONV2D_8_OUTPUT_OFFSET 0
#define RE_LU_8_OUTPUT_DEC 7
#define RE_LU_8_OUTPUT_OFFSET 0
#define CONV2D_9_OUTPUT_DEC 4
#define CONV2D_9_OUTPUT_OFFSET 0
#define RE_LU_9_OUTPUT_DEC 4
#define RE_LU_9_OUTPUT_OFFSET 0
#define CONV2D_10_OUTPUT_DEC 4
#define CONV2D_10_OUTPUT_OFFSET 0
#define RE_LU_10_OUTPUT_DEC 4
#define RE_LU_10_OUTPUT_OFFSET 0
#define CONV2D_11_OUTPUT_DEC 2
#define CONV2D_11_OUTPUT_OFFSET 0
#define RE_LU_11_OUTPUT_DEC 2
#define RE_LU_11_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_2_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_2_OUTPUT_OFFSET 0
#define FLATTEN_2_OUTPUT_DEC 2
#define FLATTEN_2_OUTPUT_OFFSET 0
#define DROPOUT_2_OUTPUT_DEC 2
#define DROPOUT_2_OUTPUT_OFFSET 0
#define DENSE_2_OUTPUT_DEC 0
#define DENSE_2_OUTPUT_OFFSET 0
#define SOFTMAX_2_OUTPUT_DEC 7
#define SOFTMAX_2_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3, 1};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
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

const nnom_io_config_t conv2d_8_input_config = {
    .super = {.name = "conv2d_8_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_8_kernel_0_data[] = TENSOR_CONV2D_8_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_8_kernel_0_dim[] = {6, 2, 1, 20};
const nnom_qformat_param_t tensor_conv2d_8_kernel_0_dec[] = TENSOR_CONV2D_8_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_8_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_8_kernel_0 = {
    .p_data = (void*)tensor_conv2d_8_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_8_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_8_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_8_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_8_bias_0_data[] = TENSOR_CONV2D_8_BIAS_0;

const nnom_shape_data_t tensor_conv2d_8_bias_0_dim[] = {20};
const nnom_qformat_param_t tensor_conv2d_8_bias_0_dec[] = TENSOR_CONV2D_8_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_8_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_8_bias_0 = {
    .p_data = (void*)tensor_conv2d_8_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_8_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_8_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_8_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_8_output_shift[] = CONV2D_8_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_8_bias_shift[] = CONV2D_8_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_8_config = {
    .super = {.name = "conv2d_8"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_8_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_8_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_8_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_8_bias_shift, 
    .filter_size = 20,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_9_kernel_0_data[] = TENSOR_CONV2D_9_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_9_kernel_0_dim[] = {4, 2, 20, 16};
const nnom_qformat_param_t tensor_conv2d_9_kernel_0_dec[] = TENSOR_CONV2D_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_9_kernel_0 = {
    .p_data = (void*)tensor_conv2d_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_9_bias_0_data[] = TENSOR_CONV2D_9_BIAS_0;

const nnom_shape_data_t tensor_conv2d_9_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_9_bias_0_dec[] = TENSOR_CONV2D_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_9_bias_0 = {
    .p_data = (void*)tensor_conv2d_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_9_output_shift[] = CONV2D_9_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_9_bias_shift[] = CONV2D_9_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_9_config = {
    .super = {.name = "conv2d_9"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_9_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_9_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_9_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_9_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_10_kernel_0_data[] = TENSOR_CONV2D_10_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_10_kernel_0_dim[] = {2, 1, 16, 16};
const nnom_qformat_param_t tensor_conv2d_10_kernel_0_dec[] = TENSOR_CONV2D_10_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_10_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_10_kernel_0 = {
    .p_data = (void*)tensor_conv2d_10_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_10_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_10_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_10_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_10_bias_0_data[] = TENSOR_CONV2D_10_BIAS_0;

const nnom_shape_data_t tensor_conv2d_10_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_10_bias_0_dec[] = TENSOR_CONV2D_10_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_10_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_10_bias_0 = {
    .p_data = (void*)tensor_conv2d_10_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_10_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_10_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_10_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_10_output_shift[] = CONV2D_10_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_10_bias_shift[] = CONV2D_10_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_10_config = {
    .super = {.name = "conv2d_10"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_10_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_10_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_10_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_10_bias_shift, 
    .filter_size = 16,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_11_kernel_0_data[] = TENSOR_CONV2D_11_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_11_kernel_0_dim[] = {2, 1, 16, 16};
const nnom_qformat_param_t tensor_conv2d_11_kernel_0_dec[] = TENSOR_CONV2D_11_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_11_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_11_kernel_0 = {
    .p_data = (void*)tensor_conv2d_11_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_11_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_11_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_11_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_11_bias_0_data[] = TENSOR_CONV2D_11_BIAS_0;

const nnom_shape_data_t tensor_conv2d_11_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_11_bias_0_dec[] = TENSOR_CONV2D_11_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_11_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_11_bias_0 = {
    .p_data = (void*)tensor_conv2d_11_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_11_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_11_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_11_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_11_output_shift[] = CONV2D_11_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_11_bias_shift[] = CONV2D_11_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_11_config = {
    .super = {.name = "conv2d_11"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_11_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_11_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_11_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_11_bias_shift, 
    .filter_size = 16,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_2_config = {
    .super = {.name = "global_max_pooling2d_2"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_2_config = {
    .super = {.name = "flatten_2"}
};
const int8_t tensor_dense_2_kernel_0_data[] = TENSOR_DENSE_2_KERNEL_0;

const nnom_shape_data_t tensor_dense_2_kernel_0_dim[] = {16, 6};
const nnom_qformat_param_t tensor_dense_2_kernel_0_dec[] = TENSOR_DENSE_2_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_2_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_2_kernel_0 = {
    .p_data = (void*)tensor_dense_2_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_2_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_2_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_2_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_2_bias_0_data[] = TENSOR_DENSE_2_BIAS_0;

const nnom_shape_data_t tensor_dense_2_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_2_bias_0_dec[] = TENSOR_DENSE_2_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_2_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_2_bias_0 = {
    .p_data = (void*)tensor_dense_2_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_2_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_2_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_2_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_2_output_shift[] = DENSE_2_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_2_bias_shift[] = DENSE_2_BIAS_LSHIFT;
const nnom_dense_config_t dense_2_config = {
    .super = {.name = "dense_2"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_2_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_2_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_2_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_2_bias_shift
};

const nnom_softmax_config_t softmax_2_config = {
    .super = {.name = "softmax_2"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_2_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_8_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_8_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_9_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_10_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_11_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_2_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_2_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_2_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_2_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_47_NNOM_H