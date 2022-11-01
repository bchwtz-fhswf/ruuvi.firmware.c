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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_12_KERNEL_0 {7, 29, 5, 23, -7, -43, -15, -26, 9, -7, -20, -48, -5, -74, 13, -49, -2, 0, 24, 26, -16, -2, 26, -36, 76, -56, 30, 20, -10, 23, -34, -19, 40, 7, 16, 0, 5, 64, -18, 49, -12, -9, 12, -62, 21, -81, 25, -35, -1, 61, -8, 22, -1, -27, 18, -3, 3, -28, 18, -66, -7, 12, 38, 4, 38, 13, -46, 36, -73, -38, -15, -37, -16, -2, -18, 11, 38, 22, -55, 21, -2, 21, -54, 60, -32, 15, -4, 21, -61, -22, 19, 19, -32, -33, 86, -11, -9, 44, 35, -37, -57, -7, -8, 33, 28, -25, 34, -45, 30, 15, 59, -30, -13, -34, -22, 32, -24, -22, -62, 52, -37, 27, -34, -63, 29, -28, -15, 33, -9, -39, 17, -18, 2, 20, 20, 8, 9, 25, 13, -18, -51, -5, -26, -1, -53, 21, -53, -17, 0, -33, 38, -6, 71, -30, 34, -29, 2, 6, -8, -7, 11, -19, 0, 4, 9, -21, 61, -23, -47, 8, 8, -9, 13, 12, -5, 2, 28, -9, 90, 27, 28, 72, -1, 32, 28, -29, 27, 24, 22, 57, 10, 86, -71, 3, 1, 38, 11, -33, -1, -56, 58, -14, -22, -7, -45, -75, -21, 19, -3, -17, -25, 18, -13, 33, 6, -45, -47, -2, -42, -7, -43, 14, -49, -9, -65, -2, -75, -38, -40, 2, -64, -43, -32, -3, -22, 30, 0, 16, 10, 40, 51, -8, -67, -5, -25, -19, 30, 12, 85, 18, 2, 6, 3, -52, -1, -11, 7, -62, 9, 8, -12, -52, 2, 36, 67, 34, -32, -14, -30, -10, 52, -9, 3, 13, -64, -23, 57, 23, 44, -1, -62, 9, 32, 33, -61, -15, -17, -8}

#define TENSOR_CONV2D_12_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_12_BIAS_0 {-10, -4, -28, -12, -20, -43, -16, -42, -33, -56, -23, -2, -49, 6, -30, -4, -32, -8, -15, 7, -87, -4, -52, -52}

#define TENSOR_CONV2D_12_BIAS_0_DEC_BITS {8}

#define CONV2D_12_BIAS_LSHIFT {7}

#define CONV2D_12_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_13_KERNEL_0 {35, -9, 22, -18, 6, 20, 26, 23, 38, -4, 17, -7, 46, -17, 43, -1, -4, 4, -78, -25, 35, -5, 6, 7, -24, -76, -11, -105, 4, -10, 12, 13, 50, 20, -71, 23, 28, -22, -62, -20, -32, -79, -57, -20, -90, -19, -10, -29, 1, -19, 18, 21, 13, -23, 11, -14, -26, -7, 40, -9, -29, 3, 10, 8, 5, -46, -25, 43, -2, -27, 40, 47, -1, -10, 9, 5, 5, -13, 17, 37, -93, 33, 13, -2, -24, -7, 9, 13, -43, -10, -14, -11, 10, -23, 3, 17, 13, 11, 32, 23, -20, 12, 14, -5, -63, -20, -24, -24, 14, 33, -23, -10, 36, 13, -35, 57, 28, -10, -4, 1, 18, -27, -30, -96, 9, 30, 0, -41, 22, 23, 24, 15, -31, 11, -5, -40, 79, 26, -4, -11, -70, 27, -98, 6, -10, -11, -55, 12, -59, -23, 19, -52, -79, -2, 3, -24, -45, 7, -27, 20, 54, 0, 17, 5, 48, 15, -5, -20, 3, -6, 2, -24, 7, 44, 15, 21, 14, 20, -50, 0, -26, 13, -13, 1, 12, -43, -20, -14, 35, -13, -9, -29, -86, 24, 32, -1, -54, -35, -36, -23, -34, 35, 19, 7, 59, -38, -41, -16, -43, -4, 5, -7, 26, -12, 23, -16, -2, -2, -6, -7, -30, -23, 0, 36, 42, 39, 51, -7, 18, 13, 36, 20, 43, 2, 9, 27, 44, 12, -10, -40, 20, 16, -19, 35, -14, -17, -18, -7, -5, 8, 34, -9, -35, -5, -44, -79, -27, 17, 39, -47, 18, -24, 44, 24, 6, 5, -72, -27, 19, 30, 19, -21, 34, 21, 3, 13, 35, 6, 12, 23, 50, -18, 12, -26, 70, 18, 39, 36, 9, -20, -42, 35, 25, 2, -69, -90, -6, 10, -56, -5, -3, -2, -17, -59, -33, 5, -2, -24, -1, 48, -14, 31, -10, -40, -12, 24, 6, 6, 14, 38, -27, 19, 13, 17, 61, -64, -3, -41, -24, -63, -25, -105, -35, 4, 44, 24, 5, -64, -11, 26, 26, -40, -44, 6, -14, 0, 5, -20, 7, 30, -59, -6, -8, -37, 35, -63, -49, -30, -39, -70, 11, 3, -10, -59, 3, -13, -24, 49, 20, 21, -41, 27, -121, -4, 58, -28, -62, -58, -14, -52, 80, 2, -38, 20, -1, 10, 35, -27, -17, -13, -26, 24, 11, 27, 33, -16, 37, 6, 60, -10, 34, 58, 11, 9, 37, 24, 35, 24, 34, 13, 39, -1, 1, 4, 14, -13, 36, -58, 40, -6, 5, -18, 9, -32, 22, 8, 30, -5, 81, -7, 57, -28, -13, -18, 9, -11, 21, -11, 36, -6, 24, 10, 20, 0, 28, 8, 38, 28, 17, 18, 25, -10, -22, 5, 20, 40, 22, 4, 17, 13, 6, 19, 30, -11, -17, 16, 30, -11, -3, -7, -3, 11, 12, 9, -6, 12, 11, -10, 32, 25, -6, -2, -1, -4, 13, -3, 4, 12, 43, 27, 25, 0, 7, 20, 4, 7, 10, 14, -13, 10, 30, 18, 18, 6, -6, -22, 1, 10, 7, 25, 16, 4, 24, 8, 22, 2, -9, -2, 1, -4, 3, 5, 4, 24, 52, -2, 40, 46, 7, 26, 0, -7, -2, 19, 3, -3, 45, 41, 6, 22, -1, 36, 67, -8, 28, 5, 15, 15, 13, 17, 32, 9, 6, 3, 5, 6, 13, 45, 14, 42, 55, -2, 1, -1, 22, -2, 44, 27, 4, -27, 15, 6, 10, -17, 40, 31, -23, 11, -16, 2, -7, 13, 2, -14, -3, -54, -26, 5, 16, -1, -38, 1, 11, 17, 45, -12, 47, -6, -28, -36, -25, 10, -21, -11, -39, 12, 12, -27, -20, -6, -11, -9, -15, -24, -28, -22, 14, 66, 65, -5, -89, 21, -28, -19, 25, 4, -46, 12, -6, 3, 1, 23, -19, -45, 20, -3, -11, -5, -1, 6, 3, 26, 0, 3, 23, 48, -10, -25, -11, 6, -22, 22, 9, -22, 21, 63, 20, 25, 9, 31, 28, -12, 10, -21, -5, -9, 32, -11, -16, 8, -33, -36, 12, -5, 42, 28, 23, -1, 22, -22, -11, -47, 23, 19, -76, -6, 29, 51, -25, 34, 9, 12, -36, -4, 14, -5, -20, -4, 72, 22, 2, -28, 7, 35, -6, -27, 44, 13, 61, -8, 7, 9, 11, 9, 5, -4, 7, -17, -19, -58, 2, 5, -4, 21, -7, -24, 16, -39, -16, -33, 21, 0, -60, 16, -51, 30, 34, 19, -20, 13, 25, -38, 35, -3, 1, 12, 10, 17, -52, 3, -8, -65, -22, -11, 8, -20, -21, 3, -23, 15, 29, 1, 8, 28, -47, 11, 19, -58, -25, 6, -19, -43, -24, 17, 14, -20, -33, -27, -26, 2, 6, -42, -32, 14, -9, -63, 14, -11, -7, 34, -18, 47, 3, -63, -15, -78, -44, -21, 18, 19, 10, 8, 33, -6, 7, 24, 27, -24, -8, -37, -13, 13, -68, 39, -32, -21, 18, -9, 15, -28, -9, -3, -20, -8, 9, 37, -5, 8, -93, 12, -3, -9, -28, -22, 11, -10, -58, -14, 5, 36, 13, -8, -31, -53, -7, -7, -14, -30, 15, -30, -60, -24, 6, -4, -38, 6, -27, -14, -1, 3, 37, 1, 1, -20, 0, 9, 3, -45, 3, 27, -19, -9, 0, 32, -2, -26, -78, 12, 1, 4, -8, -18, 6, 4, -18, 0, 13, -16, 4, -9, 11, 13, 30, -29, -34, 15, 37, 39, 18, 22, -4, -7, 12, -1, -33, 25, 26, 0, -23, 38, 20, 32, -15, -12, 39, -24, 2, -21, 35, 8, 2, 28, 6, -9, 24, 21, 8, 18, -22, 2, 27, 16, 13, -10, 14, 17, 29, -4, -26, 14, 14, -10, -10, -12, -4, -90, 12, -5, -19, 13, 59, -27, -5, 1, 14, -18, -7, 6, 37, 29, -31, 12, 3, -15, -30, 8, 2, 44, 21, 46, 15, 6, 58, -6, 41, 3, 22, 30, 9, -12, -11, 34, -15, -3, -5, 2, 3, -9, 16, -5, 3, 59, 34, -10, 21, -3, 63, -12, 17, -26, 19, 43, -13, 16, 17, -47, 13, 23, -4, -2, 8, 5, 16, -4, 0, -30, 12, 12, 36, -13, 26, -5, 20, 13, 52, -23, 25, 14, 39, -29, 44, 56, 13, -27, 23, 26, -4, 16, 22, 17, -16, 12, -5, -34, 7, -9, 2, -22, -3, 31, -17, -9, 74, 12, 48, 21, -3, -8, 45, 8, 7, 6, 21, -2, 19, 45, -12, 6, 24, -22, 17, -5, 27, 12, -3, -17, 21, 10, 8, 5, -22, -3, 2, -30, -11, 46, 19, 20, 12, 39, 23, 7, 62, -7, 14, -53, 14, -19, -22, -9, -72, -31, -57, 63, 4, -6, 23, -2, -22, 34, 28, 29, 37, 35, 9, 0, -23, -17, 26, 20, 18, -41, 36, 4, -7, 29, 33, -10, -22, 5, 20, -36, -23, 28, 33, 40, 12, -4, -49, -12, 10, 8, 7, 33, -17, 5, -7, 10, 44, -29, -81, -66, -47, 23, 20, 9, -43, -34, 6, 28, -29, 68, 11, -15, 62, 14, -9, 2, -8, 10, -3, 14, 17, 11, 10, 19, 5, -52, -5, 4, 26, 13, -21, 6, 6, -34, -12, 3, 9, 11, 30, -8, 20, -31, -53, 1, 9, -8, 7, -60, -31, -4, -6, 18, -14, 14, -50, 25, -5, 11, 27, -43, 65, 12, 2, -29, 52, -12, 11, 12, 27, -10, 40, 0, -31, 14, -51, -2, -8, -8, -39, -12, -1, -8, -9, -7, 4, 1, 35, 2, -6, -19, -51, -6, 17, -16, 25, -2, 10, -19, -60, 0, -31, -9, -18, 11, 7, 49, 6, 29, 47, 3, -10, -24, 29, 14, 48, -26, 29, 9, -37, 9, 20, -15, -45, 2, 6, -17, 0, 38, -9, -4, -26, -12, 2, -18, -43, -23, -6, -64, -8, -28, 32, 16, -57, -28, 9, -44, -38, 27, 31, 27, 11, 3, -33, 61, -25, 20, 27, -38, -69, -64, -2, -9, -38, -110, 28, 17, -21, 19, -12, -15, -18, -7, 25, -31, -11, 0, -19, -3, -35, 19, 35, -36, -12, -74, -28, -9, -80, -17, 7, 5, -19, -16, -23, 6, -20, -30, -5, 18, 4, 47, 74, 9, 40, 41, -2, -17, 48, -6, 6, 16, 26, -5, 34, 40, -44, -26, 31, -69, 14, -11, 1, -36, 12, 29, 13, -6, -8, -23, -14, -11, -28, -47, 2, -22, -13, -4, 47, -7, 69, 34, -17, 30, 27, 3, 6, -50, -23, 12, 29, -53, 15, 29, -22, 1, -13, 25, -5, -7, -23, -4, 23, 11, -17, 18, 8, -21, 18, -19, -35, 7, -7, 43, 39, -2, 21, 24, -28, 2, 14, -7, 13, 12, -15, -20, 65, -24, 31, 44, 10, 1, -5, 2, 19, -1, 38, 9, 12, 8, 42, 3, 12, -2, 14, -4, -20, 7, -9, 15, -40, 18, 59, 6, 9, -26, 24, -45, 10, -27, -5, 73, 22, -60, 17, 14, 14, 9, 40, -56, 5, -20, -2, -58, 13, -5, 36, -1, 18, 25, 35, -40, -25, -72, 4, -20, -14, -56, 12, -11, -16, 42, 39, 2, -7, 12, 31, 16, -4, 11, 41, 1, 1, -13, 10, -68, -35, -106, -16, 3, 39, -81, 17, 8, -60, 2, 25, -25, -5, -34, 0, -18, -22, 24, 24, -32, 12, 21, 34, -6, -47, -19, -3, -25, -22, 34, 22, -5, 26, 32, -17, 6, -88, -58, -25, 5, 3, -2, 20, 22, 11, -22, -1, -9, 3, -42, -43, -25, 30, -74, -30, 9, -43, 0, -72, 13, -22, -35, -55, 28, 11, -6, -13, -42, -11, 24, 12, -11, -12, 31, -34, -5, -9, -7, 16, -58, 24, 15, -56, -43, 30, 20, -13, -3, 14, -2, -17, 2, 0, 1, -6, 10, -9, -33, -5, 25, 58, 21, 17, 30, -16, -11, 12, -12, 12, 35, 10, -4, -17, -14, 18, -28, 4, -3, 19, 15, -34, 12, 0, 21, 39, -20, 50, -9, 44, -8, -42, -71, 36, 9, -27, -5, 5, 2, 7, 24, 16, 18, -34, 14, 25, 50, 3, -117, 0, 30, 12, 14, -44, -40, -19, 6, 29, 1, -7, -30, 107, 29, 57, -19, -2, -19, -20, 23, -24, -31, -41, 31, 8, 0, 14, 16, 8, 2, -2, -35, 6, -10, -53, -40, 15, 19, -50, 16, -14, -10, 30, 41, 8, 1, 19, -75, -43, 10, 25, -19, 62, -37, -102, -12, -85, 15, -65, -14, -48, -36, 43, 5, -95, 1, 18, -19, 2, 4, -24, 23, 25, 28, 34, 9, 33, 6, -7, -10, 22, 4, -17, 2, -33, -36, 11, 27, 1, 3, -82, -34, -22, -55, -1, 18, 45, -40, 14, 0, -3, 14, 29, 29, 3, -20, -10, 2, -13, -22, -8, -16, 31, 8, -29, 15, 0, -13, -9, 17, 28, 36, -9, -2, 1, 10, 37, 14, 3, 4, -23, 11, 62, 34, 55, 44, 6, 17, -63, 27, 47, 1, 22, -11, -3, -5, 21, -4, 15, 24, -2, -19, 15, 5, -2, -28, 18, 22, 25, -26, 30, -26, 12, 11, 20, -3, 0, -51, -6, 2, -3, 17, -70, -4, 12, -37, -4, 8, 18, -29, 5, 5, -78, 33, 31, -6, 24, 30, 31, 10, 8, 13, 11, -24, 10, 12, -4, -44, -40, 22, 4, 3, -35, -75, -74, -16, -16, 31, 6, -14, 34, 3, 25, 69, -16, 21, 28, 43, 15, 6, 29, 34, 2, 3, 6, -8, 21, -45, -80, -18, 18, -22, -12, -7, 24, 2, 4, 2, -1, 27, -18, 0, -14, 19, -47, 12, -9, -16, -54, -5, 74, 28, 39, -3, 17, 17, 11, 38, 19, -3, -86, -81, 10, -16, -50, 11, 41, -21, 16, 17, 37, 15, -26, -27, -11, 34, 1, 32, -22, -16, -14, -42, 8, -31, 5, 28, 42, 37, 57, -72, -8, 15, -61, -4, -24, -37, -14, -4, 13, 2, -45, 29, -67, -75, -51, 30, -15, 23, 4, 2, -34, -34, -25, -2, -14, -19, -28, -10, -18, -20, -1, 1, -48, 18, 20, -35, 31, -35, 20, -7, -7, -52, -57, 18, -16, 22, 3, -15, 44, 21, 5, -16, 4, -9, 24, -1, -31, -6, -3, 4, -14, -60, 4, 6, 22, 9, -17, -45, -14, -13, 3, 22, 40, 2, 79, 22, -17, 29, 5, 25, 20, 4, 0, -2, 29, 8, -6, -14, 21, -81, -1, -32, 0, 9, 36, -54, -30, 21, -36, 14, 45, 1, 39, -27, -6, -52, 54, 2, 29, -22, 32, -3, -25, 10, 13, -9, 2, -66, -43, 32, -21, -9, -35, 5, -60, -28, -27, -15, 23, -6, 47, 11, 16, -15, -48, -38, -33, -34, -37, -3, 23, 15, 43, 13, 5, 3, -24, 5, 10, -48, -49, -22, -10, 0, -11, 7, 52, 51, 3, -12, 22, -117, -26, 41, -9, 13, 59, 18, 61, 1, -30, 11, 63, 8, -1, 15, -49, -34, -5, -14, -5, -59, 30, -69, 9, -49, 59, -58, 50, 34, 45, -50, -6, 13, 20, 6, -8, -33, -14, 2, -92, 5, -8, -35, -22, -50, 4, 1, 37, -34, 1, 14, -29, 3, 17, 28, 35, -94, -6, 9, 11, -2, 10, -10, 3, 15, -15, -39, 15, -16, 27, -19, -20, -25, -10, -73, -23, 5, -21, -20, 1, -9, -19, -2, -41, -36, 26, 39, -32, -24, 17, 3, 26, 27, -27, 24, 50, 2, -29, -9, -20, -19, -7, -26, 25, -24, 10, 17, -30, 10, 58, 13, -6, 15, 18, -12, 25, 5, 61, -65, -55, -110, -8, 31, 22, -73, 39, 44, 9, 6, -18, 35, 14, -39, 21, 10, 23, -17, 10, 53, -62, 3, -11, 1, -2, 4, -12, 13, 14, -3, -2, 29, 44, 3, 2, -42, -21, -14, 21, -24, 12, -34, 2, 44, 4, -9, 20, 5, -28, -89, 7, 42, 10, 75, 15, 18, 13, 16, 23, 6, 33, -45, -5, -25, -32, -44, -17, 5, -63, 31, -11, 17, 35, -2, -6, -20, 6, -19, -51, -16, 13, 35, -14, 6, -47, 29, 31, 23, -3, 37, 17, 10, 22, -10, 19, 30, 39, 28, 6, 22, -71, -7, -31, 21, -9, 32, -38, 14, 7, -21, 9, 32, 7, -15, 56, 1, 40, 6, -30, 34, 16, 30, 32, -16, 22, 10, -7, 3, 12, 30, 19, -9, -33, -5, 52, 10, -15, 19, -19, 39, -33, -22, 10, -12, -30, -21, 8, 12, 17, -10, 36, 39, 8, 8, 29, -6, -21, 8, 20, 20, -2, 9, -4, 49, -7, -2, 16, -9, -42, -6, -24, -21, 35, 27, 8, -20, 28, 26, -44, -25, 2, 12, 16, 17, -25, -16, 2, 25, -3, -23, 16, 16, 8, 2, 28, -36, 14, 57, -4, 4, 22, 6, -25, -6, -5, -7, -31, -31, -82, -15, 43, -35, 11, 26, -11, -1, 6, 15, 18, 6, -27, -18, -8, -38, -45, -6, -9, 0, -24, 36, -28, 29, -85, 14, -7, -22, -22, 16, 1, 35, 41, 0, -29, -18, -43, -82, -16, -24, 31, -12, -30, 21, -24, -30, -22, 6, -31, -4, -58, -46, -16, -11, 3, 3, 41, -9, 4, 12, -84, -30, 30, 22, 31, -6, -32, -12, 4, -41, -6, -48, 14, -19, 9, -35, 47, 55, 36, -21, 0, -21, 48, 17, 25, 42, -8, 17, 40, -2, -30, -18, -78, 5, -5, 44, -9, -43, 23, 36, 20, 21, -5, -20, 7, -3, 5, -68, 4, 72, 13, 21, 49, -26, 19, -48, 29, 13, -16, 12, -5, -1, 77, -8, 64, -6, -10, -9, 12, -1, 69, 21, -17, 28, 25, -12, 23, 3, -36, -14, 14, 6, -3, -8, -3, 4, -12, -49, 31, 51, 13, -4, 0, -82, 6, 38, -36, 18, -3, 25, 5, -1, -32, -15, 25, -8, -10, 13, -17, -10, 37, -30, -39, -23, 23, -9, 28, -18, 16, 8, -42, 41, 9, 15, 17, 4, 15, 9, 6, -14, -25, 19, -94, 2, 41, -5, -80, -2, 21, -27, 58, -42, 45, 2, -64, -47, 34, -14, 19, -75, 11, -9, 31, -20, -57, -15, -17, 12, -49, 10, 39, 7, 15, -43, 19, -7, 7, -11, 21, 30, -23, 49, 25, -8, 38, -16, 51, -15, 24, 9, -63, -9, 24, 31, 22, 42, 5, 51, 15, 1, -45, -78, 13, 13, -30, -41, -33, 19, -67, 16, 3, 8, -13, -15, 8, -5, 14, 28, 58, -11, 26, -68, -11, -23, 58, 0, -5, -4, 8, -17, 7, 15, -47, 8, -1, -43, -17, 8, 49, 21, -33, -6, -46, -45, 2, 9, -40, 11, 30, 52, -32, 5, 10, -23, -2, -4, 38, 3, -19, 5, -8, 25, 22, 1, -17, 8, -5, 14, -20, 22, 13, 5, -63, 13, -55, -6, 11, -41, 74, 0, 25, 1, 3, -47, -5, 64, 47, -2, -25, -8, -15, 10, 4, 6, 23, -14, -51, 53, 30, -6, 8, -70, 21, -21, 44, -18, -15, -12, 23, 16, 28, -11, -3, -10, 13, -16, 15, 17, -18, -9, 5, 16, 9, 18, 17, -4, -22, 28, -8, 4, -13, 20, -2, -12, 37, -13, 39, 26, 1, -48, 9, 0, 36, 12, -3, -46, -16, 3, 13, -60, -1, 10, -20, 54, 18, -20, -36, 35, 16, -16, 37, 32, 50, -72, 32, -45, 30, -6, 12, 18, 31, -37, 4, -16, 8, -1, -21, -33, -22, -48, 4, 3, 34, 31, -22, 19, 27, 5, 8, 13, -3, 9, -6, -14, -31, -7, -26, 9, -3, 51, 22, 11, -18, 2, -1, 9, 35, 17, 31, 20, -26, -25, 35, 2, 43, -14, 63, 22, 26, 2, 1, -56, 24, 12, 13, -16, 2, 15, -12, -19, 6, 12, -21, 23, -20, -103, 11, -2, 18, 10, 38, -38, -49, 40, -23, 8, -12, -21, 43, -10, -3, -3, -23, 1, 10, -2, -65, 2, -42, -3, 22, 33, 35, 30, -35, 11, -10, -19, -21, 6, 24, 13, 30, -11, -20, 11, -21, -19, 12, -5, -21, 17, 15, 0, 20, -14, 24, 4, -18, -55, -19, -35, 5, 41, 1, 23, 39, 16, -2, 4, 7, 19, 0, -7, 0, 1, 20, -31, 5, 23, 6, -17, 5, -39, 12, -12, 6, -32, -11, 9, -23, 33, 17, 28, 4, -30, -2, 15, 29, -5, 36, -39, 22, -18, -18, 11, 26, -105, -26, 0, -41, 19, -2, -5, 22, 23, 4, -13, -6, -5, -2, 9, -7, 0, -39, -30, 4, -11, -20, 30, -2, -39, 2, -14, -4, 11, 29, -25, -19, 5, 26, -55, -23, 8, -5, -6, -58, -5, 15, 7}

#define TENSOR_CONV2D_13_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_13_BIAS_0 {6, -16, -61, -5, 24, -77, 9, 17, 8, -1, -4, -4, -5, -74, 6, 7}

#define TENSOR_CONV2D_13_BIAS_0_DEC_BITS {7}

#define CONV2D_13_BIAS_LSHIFT {5}

#define CONV2D_13_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_14_KERNEL_0 {4, -26, -10, 4, -17, -11, -16, 9, 4, 15, -1, -17, 8, 40, 15, -3, 30, -40, 9, 15, 4, -3, -28, 20, 16, -18, 18, -10, 4, -6, -3, 15, -8, 20, 13, 6, 3, -2, 23, -1, -25, 18, 18, -20, 11, 37, 20, 15, -7, 0, 6, 11, 21, 22, -14, 9, 3, 2, 7, 5, -11, -17, -4, 14, 26, -1, -38, 12, -19, -65, 13, 1, 17, -27, 39, 32, -2, -12, 23, 9, -23, 17, -49, 8, -6, -64, 26, -23, 9, 1, -14, 4, 18, 2, -11, -7, -25, -11, 14, -6, -14, -15, 20, -18, 16, 8, -1, -19, 14, -21, 5, -2, 14, 2, 8, 19, -34, 14, 6, -16, -12, 6, -17, 1, -25, -4, -19, 7, -18, -37, -11, 11, 2, 2, -6, 23, 3, 5, -1, -42, 2, 4, -2, -12, 25, -23, 2, 21, -9, -10, -15, 14, 27, 4, 18, -17, 18, 0, 10, 2, 1, 9, 14, -13, -1, 4, 13, 19, 3, -2, -12, 1, 18, -14, -2, 10, 8, 22, 16, -2, -5, 22, 11, 13, -11, 6, 8, -1, 1, 29, 11, -12, -4, -13, 13, -1, -31, -33, -8, -1, 8, -10, 13, -9, 8, -45, -2, 15, 3, 14, -18, 12, -11, 3, 4, -39, 14, 12, -25, -12, 20, -18, 0, -1, 4, 9, 3, 4, -13, -27, -3, 14, 10, 18, -2, 9, 2, 21, 26, -7, 6, -43, -2, 12, 4, -3, -33, 24, -25, -29, -13, 5, 13, 1, -28, -21, 9, 10, -4, -13, 14, -10, -9, 3, -6, -6, -16, 9, -20, 1, -5, 10, 7, -16, -13, 1, -9, -8, -9, 14, -14, 1, 16, -8, 7, 13, -16, -3, 29, -9, 2, 0, 1, -7, -16, 6, -46, -19, 8, -45, 19, -5, -2, 7, 7, -13, 0, 9, -28, -22, 2, 0, -43, 8, -31, -25, 7, 5, -20, -14, 4, -38, 6, -10, -14, -2, 9, 5, -10, -54, -43, 19, -33, 6, -41, -4, -43, -45, -4, -17, -11, 2, -54, 7, -37, 10, -31, 5, 6, 20, -4, -43, -4, -12, -2, 2, 18, -24, -1, -7, -6, 17, 7, -24, -8, 19, -4, -3, 12, -7, -2, 7, 20, -21, 12, -7, -17, 7, -16, 8, -19, -11, 6, -1}

#define TENSOR_CONV2D_14_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_14_BIAS_0 {53, 1, 46, -28, 63, -116, 84, 0, 7, 31, -17, -53}

#define TENSOR_CONV2D_14_BIAS_0_DEC_BITS {8}

#define CONV2D_14_BIAS_LSHIFT {1}

#define CONV2D_14_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_15_KERNEL_0 {-12, -45, 5, -33, -9, -59, 14, -45, -5, -19, -24, -15, 16, 4, 11, 26, 0, -69, -3, 30, -17, -38, -2, -11, -3, -18, -13, 6, 15, -5, -22, -15, 13, -11, -1, -4, -23, -3, 8, 18, -28, 0, 18, -8, 16, -26, -33, -1, 1, 0, -14, 8, -16, -2, 12, 5, 3, -2, -5, -14, -20, -4, -12, 3, -7, 8, -21, 8, 18, 1, 26, 1, 7, -8, 3, 7, 1, -4, -13, -36, 9, 6, 14, -19, -23, 4, 30, 5, -33, -6, 16, -11, -31, -21, -44, -1, -9, -29, 28, -19, -15, -12, 0, 3, -6, -15, 29, 7, 8, 8, -23, -22, 15, -8, 2, 4, 10, -23, 10, -12, -3, -5, 6, 0, 4, -6, -7, -33, -2, 9, 16, -20, -26, 7, 31, 8, -27, -8, 13, -10, -25, -14, -44, -6, 0, 9, -4, 4, -12, -5, 2, 0, 6, -28, 13, -11, -19, -14, 26, 14, -8, 10, -21, 17, 17, 4, 36, -14, 1, -4, -4, 13, 9, 17, -20, -42, -8, 7, 36, -18, -1, -1, -8, -5, -6, -15, -33, 5, 28, 1, -12, 20}

#define TENSOR_CONV2D_15_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_15_BIAS_0 {2, 8, -7, 7, 2, 6, -5, -10}

#define TENSOR_CONV2D_15_BIAS_0_DEC_BITS {5}

#define CONV2D_15_BIAS_LSHIFT {0}

#define CONV2D_15_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_3_KERNEL_0 {-18, -23, 3, -1, 7, 4, -20, -41, -17, 7, -38, -10, 5, 0, -3, -5, 1, -21, 6, 3, 1, -6, 0, -23, -35, -5, 9, 5, 2, 2, -11, -34, -59, -77, -35, -77, -83, -71, -27, -28, 11, -22, -28, -11, -5, -5, -22, -20}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_3_BIAS_0 {-25, -7, -50, -5, 67, 10}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {5}

#define DENSE_3_BIAS_LSHIFT {0}

#define DENSE_3_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_12_INPUT_OUTPUT_DEC 9
#define CONV2D_12_INPUT_OUTPUT_OFFSET 0
#define CONV2D_12_OUTPUT_DEC 6
#define CONV2D_12_OUTPUT_OFFSET 0
#define RE_LU_12_OUTPUT_DEC 6
#define RE_LU_12_OUTPUT_OFFSET 0
#define CONV2D_13_OUTPUT_DEC 4
#define CONV2D_13_OUTPUT_OFFSET 0
#define RE_LU_13_OUTPUT_DEC 4
#define RE_LU_13_OUTPUT_OFFSET 0
#define CONV2D_14_OUTPUT_DEC 2
#define CONV2D_14_OUTPUT_OFFSET 0
#define RE_LU_14_OUTPUT_DEC 2
#define RE_LU_14_OUTPUT_OFFSET 0
#define CONV2D_15_OUTPUT_DEC 1
#define CONV2D_15_OUTPUT_OFFSET 0
#define RE_LU_15_OUTPUT_DEC 1
#define RE_LU_15_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_OFFSET 0
#define FLATTEN_3_OUTPUT_DEC 1
#define FLATTEN_3_OUTPUT_OFFSET 0
#define DROPOUT_3_OUTPUT_DEC 1
#define DROPOUT_3_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 0
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_12_input_config = {
    .super = {.name = "conv2d_12_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_12_kernel_0_data[] = TENSOR_CONV2D_12_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_12_kernel_0_dim[] = {6, 2, 1, 24};
const nnom_qformat_param_t tensor_conv2d_12_kernel_0_dec[] = TENSOR_CONV2D_12_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_12_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_12_kernel_0 = {
    .p_data = (void*)tensor_conv2d_12_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_12_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_12_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_12_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_12_bias_0_data[] = TENSOR_CONV2D_12_BIAS_0;

const nnom_shape_data_t tensor_conv2d_12_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_conv2d_12_bias_0_dec[] = TENSOR_CONV2D_12_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_12_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_12_bias_0 = {
    .p_data = (void*)tensor_conv2d_12_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_12_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_12_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_12_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_12_output_shift[] = CONV2D_12_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_12_bias_shift[] = CONV2D_12_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_12_config = {
    .super = {.name = "conv2d_12"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_12_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_12_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_12_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_12_bias_shift, 
    .filter_size = 24,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_13_kernel_0_data[] = TENSOR_CONV2D_13_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_13_kernel_0_dim[] = {4, 2, 24, 16};
const nnom_qformat_param_t tensor_conv2d_13_kernel_0_dec[] = TENSOR_CONV2D_13_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_13_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_13_kernel_0 = {
    .p_data = (void*)tensor_conv2d_13_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_13_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_13_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_13_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_13_bias_0_data[] = TENSOR_CONV2D_13_BIAS_0;

const nnom_shape_data_t tensor_conv2d_13_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_13_bias_0_dec[] = TENSOR_CONV2D_13_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_13_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_13_bias_0 = {
    .p_data = (void*)tensor_conv2d_13_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_13_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_13_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_13_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_13_output_shift[] = CONV2D_13_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_13_bias_shift[] = CONV2D_13_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_13_config = {
    .super = {.name = "conv2d_13"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_13_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_13_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_13_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_13_bias_shift, 
    .filter_size = 16,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_14_kernel_0_data[] = TENSOR_CONV2D_14_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_14_kernel_0_dim[] = {2, 1, 16, 12};
const nnom_qformat_param_t tensor_conv2d_14_kernel_0_dec[] = TENSOR_CONV2D_14_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_14_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_14_kernel_0 = {
    .p_data = (void*)tensor_conv2d_14_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_14_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_14_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_14_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_14_bias_0_data[] = TENSOR_CONV2D_14_BIAS_0;

const nnom_shape_data_t tensor_conv2d_14_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_14_bias_0_dec[] = TENSOR_CONV2D_14_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_14_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_14_bias_0 = {
    .p_data = (void*)tensor_conv2d_14_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_14_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_14_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_14_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_14_output_shift[] = CONV2D_14_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_14_bias_shift[] = CONV2D_14_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_14_config = {
    .super = {.name = "conv2d_14"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_14_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_14_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_14_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_14_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_15_kernel_0_data[] = TENSOR_CONV2D_15_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_15_kernel_0_dim[] = {2, 1, 12, 8};
const nnom_qformat_param_t tensor_conv2d_15_kernel_0_dec[] = TENSOR_CONV2D_15_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_15_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_15_kernel_0 = {
    .p_data = (void*)tensor_conv2d_15_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_15_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_15_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_15_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_15_bias_0_data[] = TENSOR_CONV2D_15_BIAS_0;

const nnom_shape_data_t tensor_conv2d_15_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_15_bias_0_dec[] = TENSOR_CONV2D_15_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_15_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_15_bias_0 = {
    .p_data = (void*)tensor_conv2d_15_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_15_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_15_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_15_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_15_output_shift[] = CONV2D_15_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_15_bias_shift[] = CONV2D_15_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_15_config = {
    .super = {.name = "conv2d_15"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_15_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_15_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_15_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_15_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_3_config = {
    .super = {.name = "global_max_pooling2d_3"},
    .output_shift = 0,
};

const nnom_flatten_config_t flatten_3_config = {
    .super = {.name = "flatten_3"}
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_3_kernel_0_dec[] = TENSOR_DENSE_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_3_kernel_0 = {
    .p_data = (void*)tensor_dense_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_3_bias_0_data[] = TENSOR_DENSE_3_BIAS_0;

const nnom_shape_data_t tensor_dense_3_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_3_bias_0_dec[] = TENSOR_DENSE_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_3_bias_0 = {
    .p_data = (void*)tensor_dense_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_3_output_shift[] = DENSE_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_3_bias_shift[] = DENSE_3_BIAS_LSHIFT;
const nnom_dense_config_t dense_3_config = {
    .super = {.name = "dense_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_3_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_3_bias_shift
};

const nnom_softmax_config_t softmax_3_config = {
    .super = {.name = "softmax_3"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_3_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_12_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_12_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_13_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_14_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_15_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_3_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_3_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_3_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_3_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_22_NNOM_H