#ifndef MODEL_23_NNOM_H
#define MODEL_23_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_23_nnom
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
#define TENSOR_GRU_9_GRU_CELL_9_KERNEL_0 {-14, -56, 28, -18, -28, 15, 24, -68, 47, 64, 46, -16, -21, -7, -22, -33, -67, -8, 67, 20, -33, 45, -5, 10, 77, -2, 27, -34, -9, -100, -44, -39, 12, 43, 46, -57, 18, 9, -58, -26, -45, 62, 5, -52, -71, 7, 71, -15, -12, -40, -9, 50, -37, -3, -5, -40, -9, 42, -34, 39, -19, -32, -6, 5, 13, -34, 0, -9, 12, -18, -28, 34, -5, 43, -24, -12, 23, -19, -41, -3, 28, 18, -16, -42, 40, 16, -49, -5, 9, -10, 4, -34, 21, -27, -40, -58, -6, 26, 65, 51, 25, 6, 0, 36, -2, -5, -14, -10, 42, -39, -9, -47, -79, 4, 16, 18, -81, -11, -18, -10, -1, 55, 24, 23, -7, 72, -52, -61, -4, -42, 48, -4, -48, 56, -21, -19, 46, 35, -82, 45, -41, -26, 8, 8, 47, -62, 68, 37, -6, 63, -39, 65, 30, 12, 8, 39, -49, -24, 57, 32, -14, 61, 26, -22, 49, -13, 50, 16, 14, 67, 48, -53, 26, -19, 47, -55, 31, -14, -41, 2}

#define TENSOR_GRU_9_GRU_CELL_9_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0 {-18, 20, -14, 22, 0, 13, -26, -18, 1, -27, -4, 23, 14, 17, 16, -46, 39, -21, 1, 39, 1, -28, -35, -36, 3, -5, -24, 13, 39, -34, -35, -34, 11, 54, -4, -21, -22, 17, 23, 46, -3, -19, -39, 38, 19, -12, -29, 7, -17, -1, -25, 5, 5, 22, -6, 20, 25, 7, 14, 37, 28, 46, -14, -32, 9, 37, -29, 18, -20, 2, 20, -35, -18, 25, 2, -18, -47, -23, 38, 3, -8, 40, -6, 6, -34, -4, -1, -7, 2, -19, 21, 10, 43, 30, 50, -17, -18, 2, -6, 4, 25, 23, 19, 4, -4, -5, -1, -14, 29, 36, -37, -24, 13, -32, -27, -22, -26, -24, -32, 35, -13, -27, -2, -12, 26, 6, -25, -28, 18, 21, -41, 33, -68, 13, -37, -7, 11, 9, 40, -5, -37, 3, 33, -7, 6, -21, 14, -22, -41, -16, 29, -1, 2, 6, -5, 33, -35, -4, 17, -2, -8, -15, -46, 7, -6, 24, -18, 2, 57, 6, 49, -4, 8, -16, 3, -9, 39, 42, -56, -34, 27, -37, -4, 34, 48, 23, -43, 4, -10, 21, -37, 21, -41, -37, -21, 36, -4, 56, -4, -22, 30, 17, -70, 18, 4, -12, -32, 42, -29, 27, -24, -1, -7, 55, -17, 19, -7, -4, 1, -41, -1, 4, -1, 35, -80, -8, 0, -22, 0, 37, -16, 30, -45, -7, 20, -2, 15, 23, 7, -25, 21, 19, -2, -4, 3, 26, -26, -29, -23, -21, -17, -4, 4, -13, 33, -8, -30, -24, 2, -55, 35, -1, -2, -35, -33, -51, 32, 31, -13, -41, -41, -2, 26, 32, 11, 18, -5, 6, -6, 40, -37, -25, 30, 4, 13, -3, -55, -41, 37, 9, 32, 2, -28, -14, -20, -5, 26, 30, -14, -21, -26, 37, -5, -26, 18, -15, -4, -27, -44, -45, -45, -23, 36, 22, -23, -26, -24, -20, 26, -7, 9, -19, -20, 32, 23, 3, 9, 19, 3, 21, -36, 30, -49, -11, 14, -1, 3, -12, -10, 37, -39, -1, 6, -19, -17, 30, 0, 5, -42, -3, 17, 2, 33, -24, -1, -36, 42, 12, 4, 10, -41, 35, -18, 41, -45, 1, 14, 14, 11, -55, 4, -31, 11, 10, 14, -4, 23, -42, 6, 48, 48, 10, -17, 19, 11, 5, -19, 50, 22, 17, -11, -22, 7, -4, -9, -16, 43, -10, -26, -29, 8, 12, 14, 30, 2, 1, 15, -15, -15, -50, 14, -33, -15, -15, -22, 17, 7, -1, 5, -2, -10, -13, -10, 13, -4, -28, -10, 1, -7, 22, 17, 6, 5, 19, -3, 1, -5, -27, 22, 12, -8, 0, 17, -30, 12, 16, 16, -5, -7, -20, 15, -7, -35, 8, -18, 1, -38, -2, -18, -15, 20, -13, -1, -2, -10, -16, 11, -30, 8, -1, 20, 26, 22, 19, -8, -16, -2, 9, -4, 1, -21, 32, 22, 18, -3, -12, 2, 25, 45, -1, -26, -2, -11, 19, -17, 32, -10, -10, 2, -35, 4, 24, 6, 29, 62, 15, 28, -11, -21, 0, 19, -3, -62, 34, 18, -23, 17, 4, -26, -24, 17, -15, 6, 1, -56, -7, -5, -3, 48, -7, 32, -19, 8, -35, -6, -21, -7, 18, -50, 0, 4, -16, 2, -3, 4, -10, 15, -5, 11, -17, -5, 10, 0, -18, 1, -22, 5, -42, 17, 34, -6, -8, -13, 28, 14, -3, 0, 4, 24, -21, -16, -39, -22, 0, -40, -45, -3, -40, -2, 35, -19, -24, -34, 26, -24, -14, -26, 19, 14, -17, 10, -8, 28, 21, -17, 21, -4, 27, 16, -19, -12, 16, -14, 48, 1, -35, 13, 8, 9, 21, 4, 23, 49, 2, 12, 17, -1, -5, 5, 19, 2, 7, -17, 30, 18, 35, -11, 16, 22, 39, -1, 19, -11, 24, 7, -28, 11, 41, -23, -6, 1, -17, -38, -18, 12, 5, 24, -8, 0, 23, -3, 13, -28, 16, -41, -12, -11, 4, -10, 33, -24, 18, -4, -36, -6, 1, -35, -19, 21, 2, 35, -13, -8, -16, -3, 0, 6, -15, 8, 33, 24, 13, -18, -4, -30, 10, 14, 5, -16, -35, -33, -16, -4, 19, 5, 33, 0, -14, 8, 34, 7, -4, -9, -30, -15, 1, 12, -1, 18, 4, 10, -1, -22, -24, 17, 17, 34, -19, -18, 13, -23, -8, 15, 4, -8, 18, -44, -50, 42, -11, 2, -20, 28, -15, -27, 14, 43, 34, 10, 2, 14, 18, 3, -2, 5, -7, -19, 8, -11, -11, 6, 13, -5, -25, -16, 0, 5, 28, -6, -3, 6, -17, -7, -4, -10, -41, -31, -8, 13, 27, 6, 16, -6, 7, 10, 11, -42, -22, -9, -26, -3, -3, -2, 0, -14, 16, -2, -2, 3, 5, 6, -4, -38, 11, 6, -1, 7, 25, 21, -33, 7, 13, -22, 13, 5, -10, 10, -27, -8, 6, 10, -9, -7, 18, -11, 2, 2, 27, -5, -3, 6, 0, -6, -14, 0, 4, -13, -27, 2, -10, 10, 2, 0, -5, 11, -2, 18, -5, -26, 14, -11, 5, -29, 13, -3, 3, -4, -7, -4, -7, 17, 7, -4, 7, -1, -7, 18, -37, -28, -5, -2, 3, 14, -14, -17, -23, 13, -9, 11, 8, -9, -10, -3, -10, 40, -9, -1, -15, -4, -15, 13, -3, -28, 12, 3, 8, 9, -13, 11, 2, -3, 24, -12, -1, -12, -30, -1, -22, 9, 18, 0, 3, -20, -6, 6, 14, 3, 3, -2, 5, 3, 5, 4, 23, 0, -23, -2, -13, 9, 20, 23, 4, -19, 34, -17, 16, 12, 16, -9, -4, 0, 7, 19, 32, 12, 6, -8, 6, 26, 11, 16, -7, -22, 0, -9, 9, -12, 35, -8, 10, -1, -4, -3, 3, -8, 0, -8, -7, -8, 4, 5, -10, -2, 0, 7, 13, 4, -11, 15, -11, 23, -14, -31, -3, -18, -13, -6, 1, -6, 5, -8, 11, -14, -9, -1, -11, 1, -9, -3, 6, 0, -6, -5, 22, -26, 12, -2, -15, 21, 7, -6, -4, -21, 7, -7, 8, -2, 11, -31, 8, -10, 17, 2, -5, 4, -7, 2, -3, 6, 2, 9, -5, -15, -8, -1, 14, 5, -5, 7, -13, 9, 16, -10, 22, 10, -24, 9, 9, -16, 0, -5, -8, 10, -9, -25, 14, 4, 2, 5, 23, 13, 15, 15, -17, 9, 8, 1, -7, 3, 10, 7, -24, 2, 8, 8, 7, -26, -29, 5, 2, -26, 18, -24, -3, -4, 3, -10, 14, 16, -15, 0, -1, -3, 3, 4, -8, -8, -6, 2, -3, -2, -6, 7, -10, -4, 1, -3, 8, 11, 19, -10, 3, -6, 2, -6, -5, 4, 8, 21, 0, -2, 14, -9, -37, 16, 20, -6, 36, 16, 1, -2, -25, 12, -4, -3, -2, -5, 5, -8, -13, -18, -14, 7, 6, 10, 25, -10, 6, 15, 7, 6, 6, -19, 25, 14, 0, 16, 10, 33, 20, 18, -14, 3, 6, -20, -8, -7, -21, -21, -9, 4, -10, 8, 15, 2, 8, 19, -5, 7, 11, -17, 12, 7, -17, 8, -12, -10, -1, 8, -7, 4, -3, -6, 7, 6, 12, -3, 2, 9, -6, -8, 33, 1, 6, -5, 3, -11, -11, 12, 20}

#define TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_9_GRU_CELL_9_BIAS_0 {-90, -21, -113, -31, -91, -58, 19, -115, -48, -105, -94, 4, -28, -27, -26, -104, -107, -1, -73, -72, 106, -2, -46, 0, -13, 43, -28, -12, -25, -79, 9, -62, -38, 22, 27, -10, -19, -10, -14, 18, 7, -7, -1, 3, -1, -1, -7, 19, 2, -5, -9, -3, -8, -11, 12, 3, 3, -4, -1, 9, -90, -21, -113, -31, -91, -58, 19, -115, -48, -105, -94, 4, -28, -27, -26, -104, -107, -1, -73, -72, 106, -2, -46, 0, -13, 43, -28, -12, -25, -79, 9, -62, -38, 22, 27, -10, -19, -10, -14, 18, 8, -6, -7, 1, 5, 9, -11, -2, 1, -21, 12, -8, -10, -4, -1, 1, -14, 0, -6, -1}

#define TENSOR_GRU_9_GRU_CELL_9_BIAS_0_DEC_BITS {7}

#define GRU_9_BIAS_LSHIFT {7}

#define GRU_9_OUTPUT_RSHIFT {7}

#define TENSOR_GRU_10_GRU_CELL_10_KERNEL_0 {111, -55, -9, -48, -18, -16, 11, -13, -108, 30, -30, 31, 2, 45, -4, 69, -48, 52, -42, 33, 8, 22, -4, 53, -38, -19, 53, -47, 20, 47, -17, -50, 60, -31, -22, 15, -43, -54, 34, -19, -92, 55, 26, -50, 25, 28, -3, -21, 36, -59, 74, -75, -7, -18, 10, 9, 75, -41, -38, 8, -14, -27, -20, 24, 30, -15, -30, -31, -25, -42, 27, 44, 76, -53, -25, 45, -12, -48, 22, 32, -32, -8, -23, 7, 29, -21, -17, 4, -22, 18, 8, -1, -16, 19, -13, 9, 100, 12, 53, 18, 38, 0, 1, -25, -16, 26, -47, -46, 38, 43, -27, -7, -44, -33, 4, 24, -39, -81, 30, 40, -8, 31, -27, 6, -17, 56, 8, -12, -23, 8, 3, -8, 51, 7, 73, -7, -3, -20, -35, 29, 10, -10, -53, -44, -16, -19, -5, 19, -22, -25, -7, 37, -46, -13, 28, 12, 2, -27, 4, 12, 9, -40, -2, -33, 7, -40, -3, 9, -7, 41, 38, 69, 21, 26, 12, -1, -19, 61, 33, 33, -5, -2, 38, 11, 15, 42, 5, -68, 28, 31, 32, 1, 36, -41, -68, -15, 1, -21, -23, 34, -10, 36, 4, -21, 38, 46, 16, 15, -24, -28, -30, -16, -7, -10, -2, 1, 6, -29, 30, 9, -23, -31, 36, -14, 9, -43, 21, 15, 7, 15, 33, 18, 25, -32, 0, 49, 9, -4, -5, -11, -44, 20, 9, 5, -20, 5, 28, -5, 21, 11, -2, -5, -32, -2, 11, -18, 17, -37, -1, 11, 9, -17, 25, 19, 59, 6, -6, 9, 5, -1, 60, 59, -77, -16, -9, 8, 2, 11, -42, -21, 5, 48, -12, 33, -6, 14, 26, 54, 10, 11, 0, 3, 2, 19, 0, 11, -8, -3, -31, 29, -18, 5, -2, 22, -8, -10, 49, 32, 30, 49, 30, 27, 9, -9, 14, -13, 18, 37, -28, -41, -51, -13, 21, 1, -2, 9, -8, -1, 53, 39, 1, 21, -17, -1, -5, -48, 1, 16, 60, 31, -11, 2, -31, -16, 29, 18, 15, -25, -20, -10, -4, 23, 19, -31, -20, -20, 1, -14, 26, 1, 1, 15, 27, -30, 9, -10, -1, 1, 0, -13, 7, -14, -11, 28, -25, 29, -36, -10, 40, -6, 15, 5, -5, -41, 58, -21, 14, 28, 0, 13, -12, 15, -4, -12, -5, 41, -14, 1, -33, 21, -12, -10, -8, -33, 22, 11, 46, 29, 11, 9, -16, 8, -16, -4, -7, -19, 27, 3, 1, -16, -30, -36, -10, -29, -34, 23, -11, -4, 1, 25, -15, 26, 12, -47, 7, 0, 21, -6, -1, 44, -28, 25, -11, -30, -40, 12, -2, 26, -4, -7, 12, -7, 1, 36, 4, 7, 17, 13, 16, -25, 20, 24, -5, -37, -7, -2, -17, 9, 5, 10, 1, -1, -15, -29, 26, 22, 24, 3, 23, -17, -14, 23, -14, 8, -3, -2, -22, -22, -52, -25, 7, -4, 15, 20, 6, 12, -2, 4, -7, -34, -11, -26, -2, 2, -33, 12, 4, -11, -28, 1, -19, -14, 5, -42, 15, 15, 24, 7, -37, -4, 11, 11, -8, -4, -13, -28, 16, -12, -6, 23, -28, 32, 18, 23, 9, 9, -8, 10, 20, -75, -13, 6, 24, 10, 0, -59, -13, -5, -5, -2, 8, 7, 22, -19, -17, 2, -4, -8, 9, 44, -6, 29, 3, -15, -36, -51, 13, 18, 6, 11, -2, 1, 24, 29, -42, -24, 11, 27, -32, -5, 1, -14, -26, 21, -4, -26, 4, -38, 10, 22, -6, 5, -3, 40, -9, -64, 5, -6, 30, 43, -2, -30, -4, -58, 3, 16, 0, 13, 3, -48, -12, -17, 14, -6, -10, -7, -18, -17, 14, 49, -31, -19, -21, 17, 20, -20, -35, -2, 13, 32, 7, 23, -5, -9, -13, 32, 0, 5, -11, -18, 52, -19, -1, -34, -24, -29, -4, 5, -33, 11, 15, 8, 24, -7, 1, -6, -22, 17, -6, 19, 27, 11, -2, -20, -13, -8, 20, -20, -9, -8, -21, 1, 13, -3, -10, -7, -7, 24, -8, 18, -23, -12, 19, -52, 1, 14, -31, 1, 10, -19, 8, -7, -17, -3, -5, -15, 25, 11, -10, 29, -26, -13, 10, 6, -7, 6, -6, 5, -7, 15, -9, -11, 17, -15, -16, 29, -7, 0, 19, -27, 6, 14, -10, 0, 22, 5, 11, 6, -11, -33, -37, -19, -32, -6, -14, 0, 16, -16, -21, -17, -13, 7, -12, 10, -14, -8, 14, 16, -17, -7, -4, 0, 8, 20, -2, 0, 25, 12, -7, -4, -20, -4, 4, 29, -22, -23, -12, 0, 11, 13, 8, 19, 15, -1, 24, 1, -3, 21, -3, -6, 17, 7, -11, 21, 9, 13, -21, -13, -5, 31, 6, 1, -1, 27, -7, -9, 8, 13, 11, 11, 18, -49, -31, 32, -5, 12, 17, 12, -17, 0, 42, -16, 0, -2, -27, -24, 10, 22, -5, 6, 5, -29, -25, 2, -5, -9, 8, 0, 15, 0, 1, 30, 14, 14, -12, 1, 3, 10, 27, -15, 1, -7, -16, -4, 8, -17, 16, 34, -27, -3, -9, -3, -11, 25, 3, 8, -5, -6, 8, -11, 0, -12, -24, 3, -23, 7, -6, -9, 5, 14, -2, 8, -5, -4, 0, 5, 4, 27, -15, -7, 14, 35, 15, -16, 16, -24, 0, -12, -5, -20, 11, 9, -6, -8, 9, -4, 36, 4, -23, -2, -8, 5, 5, -10, 15, -29, 12, -8, 7, -5, -6, 0, -37, 33, -10, -11, -16, 14, 6, 0, -7, 4, -8, -39, 14, -8, -7, 7, 10, -15, -1, -2, 6, -10, 18, -14, -15, -9, -13, -2, 20, 13, -3, 3, -7, -30, -14, -33, -14, 16, -3, 13, 28, 10, 0, -2, -17, -2, 2, -13}

#define TENSOR_GRU_10_GRU_CELL_10_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0 {-48, -20, 80, -89, -15, -22, -12, -34, 22, -59, -78, -13, -36, -30, -33, -7, -108, 33, -44, -53, 2, 0, 60, -4, 13, -22, -38, -41, -35, -5, 10, 8, 8, 16, 77, -88, -41, 73, -36, -21, -61, -54, -104, 78, -50, -53, 24, 23, -61, 43, -10, 13, -33, 23, -30, -14, 18, -26, -8, 7, -76, -19, 16, -2, -2, 11, 23, -22, -43, -28, 40, -27, 99, -16, -14, -81, -2, -61, 57, 63, 28, -4, -61, 38, -39, 13, -52, 105, -41, 13, 40, 28, -42, -46, -25, 34, -10, 17, -61, -54, 15, -82, -15, 7, 6, -28, -59, 21, 6, 2, -39, -15, -48, -65, -37, 54, -60, 44, -33, 5, 4, -29, -1, 65, 31, 16, -19, -27, -13, 2, 13, 2, -31, -53, 3, -21, -32, 31, -11, -19, 2, -43, -23, -25, 11, -20, -10, -44, 42, 21, 40, 57, -16, -24, -10, -15, -32, -45, -20, 26, -20, 54, 1, -65, -15, -32, -57, -50, 5, -18, 9, 5, -110, 32, 48, -1, -74, 58, -9, -5, -30, -10, 10, -26, -20, -18, -31, -18, -34, -2, -13, 37, -28, -8, -41, -29, -61, -73, 9, -6, 27, -11, 48, 88, -27, 4, 11, 10, 24, 4, -28, 4, 40, 30, 35, 15, -9, -24, 9, -15, -52, 14, -63, -71, -49, -22, 20, 40, 8, -32, -29, -46, -28, -7, 40, 1, -67, -58, 37, 22, 34, 31, -5, -10, 30, -15, 19, 2, 8, -1, -36, -30, 15, -9, -23, -52, 20, 20, -44, -12, 12, 6, 32, -4, -32, -9, 0, 46, -31, 36, -4, -20, 12, -29, 23, -6, 1, -2, 19, -21, 9, 28, 20, 1, -9, 11, 15, 34, 10, -37, -38, 50, 19, -41, 1, -22, 7, 27, 18, -4, -4, 59, -40, -34, 18, -19, 4, -25, -1, -13, -26, 2, 9, 6, 1, 5, 42, 33, -6, -14, 37, -2, 15, -9, 16, -62, -1, -52, 58, -31, 3, 22, 20, -32, 25, -30, -7, -2, -32, 1, -17, 40, -67, 12, 35, -12, 27, 35, 33, -30, 15, -26, 15, -36, 5, 3, -20, -34, 39, -44, 6, 29, -25, 15, -2, -39, 10, 23, -8, 17, 1, -29, -10, 36, 30, -16, 1, 43, 14, -19, -61, 29, 53, 22, 1, -13, 10, -1, -31, 22, -29, -8, -46, 26, 20, 53, -14, 40, -9, 17, 27, -6, 20, -15, 47, -20, -8, -6, -1, -38, 33, -4, 27, -18, -15, 14, -19, -26, 7, 16, -15, -10, -52, 40, 16, 1, 9, 18, -31, -21, 1, 13, -8, -16, 7, 1, 14, -35, 0, -32, -32, -8, 42, 13, -39, -32, 18, 20, 17, 20, -6, 35, -27, -24, -78, -44, -10, 54, -21, 28, -41, -82, -4, 57, 14, -12, 36, -75, 83, 16, 8, 8, 14, 22, -42, 12, -50, -28, 39, 19, -12, 44, -21, 37, -9, -64, -52, -17, 17, 8, 9, -18, -6, -8, 69, 53, -1, -44, -15, 24, 68, 17, -5, -41, -59, -16, 70, 35, 8, -6, 20, 9, 34, 11, 9, 33, 35, 23, -27, 5, 1, 32, 40, -24, 22, -24, 22, -51, -19, -9, -34, -12, 25, -16, -27, 38, -40, 34, 27, -15, 0, -9, 3, 19, -7, 24, 36, 12, -4, -6, 29, -55, 2, -22, 8, -23, 3, 21, 29, 14, 6, 10, -18, 2, 28, -1, 10, 12, 30, -56, -57, 34, 7, 1, 25, -2, 0, -1, -34, 49, 3, 13, -32, -6, -1, 58, -11, -6, -7, -4, 20, 20, 22, -22, 25, -35, 17, -7, -63, 2, -33, -7, 38, 0, 32, -68, 1, 27, 15, 21, -45, 14, -12, -4, -8, -14, 19, 26, 30, -35, -23, 25, 20, 29, 15, -9, -7, -10, 5, 18, 24, -59, 23, 11, -31, 22, -34, 7, 29, -40, -3, 16, 1, -5, 10, -13, 36, -31, 26, 31, 34, 43, -31, -34, 3, -1, 11, 33, -15, -38, -43, 37, 30, 20, -4, -1, 16, -2, 1, -14, -8, 39, 25, 16, 29, -34, -5, -2, -8, -3, -12, 26, -2, -1, 18, -5, -18, 34, 24, 17, -10, 38, -28, 4, -15, -23, 23, 5, -36, -6, 38, 0, 11, -49, -16, -22, 3, -33, 27, -12, 25, -18, -28, -20, -13, 62, 10, 9, 10, -78, -5, 30, 25, -35, -9, 2, 32, 22, -42, -14, -5, -33, -28, 14, 6, -6, 9, -14, -26, 3, -38, 23, 27, -40, -6, -16, -2, 40, 25, -36, -30, 14, 18, 32, -33, 2, 3, -15, -38, -7, 38, 13, -54, -9, 17, -44, -15, 40}

#define TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_10_GRU_CELL_10_BIAS_0 {60, 81, -22, 33, -54, -34, 100, 44, -47, -9, 81, 116, 84, -11, 58, 88, 12, -10, -33, -41, 8, -15, -23, -1, -36, -23, 9, 16, 9, -35, -6, -23, 6, -9, 29, -16, 22, -16, 19, -7, 25, 9, 0, 14, -15, 18, 0, 4, 60, 81, -22, 33, -54, -34, 100, 44, -47, -9, 81, 116, 84, -11, 58, 88, 12, -10, -33, -41, 8, -15, -23, -1, -36, -23, 9, 16, 9, -35, -6, -23, -6, -17, 16, -14, 25, -19, 27, -13, 25, 1, -17, 25, -12, 17, -38, 10}

#define TENSOR_GRU_10_GRU_CELL_10_BIAS_0_DEC_BITS {7}

#define GRU_10_BIAS_LSHIFT {5}

#define GRU_10_OUTPUT_RSHIFT {5}

#define TENSOR_GRU_11_GRU_CELL_11_KERNEL_0 {-31, -25, -3, 10, -10, -6, -17, -15, 37, 24, 23, 20, -9, -13, -21, -13, 7, -14, -30, -42, 23, -14, 1, -18, -2, 47, -25, -41, 9, 29, 18, -4, 9, 5, 40, 26, -11, 1, 7, 32, -28, -18, -16, -20, 5, 5, 18, -10, -49, 2, 2, 5, -11, -32, 28, 12, -1, -19, 5, 44, 10, -12, -20, 14, -16, 0, -19, -3, -48, -15, -5, -8, -20, 31, 6, -13, -9, -3, -1, -2, -3, -25, 9, -55, -5, 20, 15, 1, -21, 56, 21, -20, -14, 19, -6, 0, -17, 33, 1, 1, 28, 15, -8, 2, 10, -9, 2, -4, -18, 14, 9, 10, 5, -7, -26, 19, 15, -11, 12, 34, -5, -2, -2, 25, 14, 5, -6, 7, -19, -14, 3, -4, 2, -18, -1, -10, -20, -4, -20, 5, 32, 41, -11, 8, 40, -5, 35, -4, 18, -11, 1, -33, -17, -17, 34, -4, 25, 10, 1, -2, 0, -25, 11, -17, 36, 13, -3, 6, 10, 0, 25, -2, 6, -7, -5, -6, 3, 6, -8, -9, -3, -21, 45, 10, 15, 15, -6, -16, 26, 1, -11, -5, -18, -7, 0, -13, -20, 1, -19, 17, 5, -2, 12, -4, 18, 39, 5, 11, -9, 17, -15, 35, 13, -10, -3, -33, 0, -18, 5, 9, -12, 18, -1, -28, -1, -3, 14, -13, 31, 8, -6, 5, 17, 13, -9, 5, -32, -1, -3, -28, 3, 42, -22, -1, 35, -10, 22, 29, 17, 13, 9, 7, 1, 4, 15, 3, -42, -1, -30, 4, -1, 9, -5, -3, -21, 21, 1, -1, 2, 6, -7, 39, 0, -13, 7, -12, -3, -2, -16, -2, -1, -1, 3, -24, 14, -16, 1, 22, -1, -29, -27, 0, 16, 9, -1, 14, -2, -2, 7, -2, -17, 0, 18, -2, -1, 10, -3, -2, 0, 19, 0, 3, -3, 2, -10, -10, -13, 11, 5, -26, 12, 1, -3, -2, -8, -9, -8, 12, 1, 19, -4, 18, -8, 7, -4, -6, -6, 39, -28, 6, 13, -13, 36, -20, 13, -12, -18, 7, -3, 1, -4, -26, 4, 35, 19, 1, -9, 32, -33, -6, -9, -30, -18, 8, 11, -30, 0, -12, 12, 11, 82, 24, 1, 8, -35, 12, -15, 5, 29, -19, 2, -11, 20, 26, -87, 16, -27, -1, 16, 0, 9, 10, -50, 7, -8, -12, -1, -5, 24, 7, 11, -6, 4, -39, -17, -11, -13, -24, -7, 19, 8, -16, 16, 12, -1, -16, 8, -3, -33, 21, 20, 16, 17, -12, 8, -8, 3, -17, -12, -3, -12, -5, 19, -19, 10, 12, 3, -35, 3, 30, 15, -24, -40, 11, 15, -20, -15, -7, 7, -3, 14, -5, -26, -13, -16, 1, -8, 5, 10, 2, 7, -7, 6, -19, -29, -2, 11, -24, 8, 2, -24, -3, 16, 15, -6, -33, -11, 7, 26, -22, 7, -5, 15, 6, -7, -19, 3, -21, 17, -2, -22, -8, -27, 15, 22, -11, 7, -22, 14, 20, 14, -14, 2, -16, 2, -26, -3, 11, -5, -7, 13, 15, 17, 10, -6, -4, 2, 7, 10, 9, -16, 26, 8, 3, -8, -10, 16, -3, 17, 9, -2, -13, -2, -18, 14, 14, 1, 22, 22, 6, 5, -14, 2, 14, -16, 24, -5, 5, -14, -14, 17, -10, 20, -13, 18, 2, 9, 16, 4, 1, -9, -7, -7, 17, 5, -2, 17, -18, 5, 4, -19, 4, 4, 16, -17, -22}

#define TENSOR_GRU_11_GRU_CELL_11_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0 {92, 23, -65, -31, 44, 64, 29, -33, 42, 19, -7, 4, 36, 29, 13, 16, -31, -17, -31, 69, 56, 12, -24, -7, 56, 8, -38, -40, 73, 43, -27, -10, -8, -16, 102, -1, -29, -28, 3, 12, -46, -13, 31, -23, 10, -11, 12, -8, 27, 50, -30, -38, 54, 57, -39, -1, 17, -3, 17, -34, 35, 38, 3, -1, -56, -2, -6, -71, -37, 38, -16, -30, 52, 82, -54, -7, 4, 34, 12, 23, 3, -31, -6, 13, -60, -46, 48, 18, -12, 0, -39, -26, -56, -6, -1, 20, 13, 27, -4, -17, 17, 25, 7, 6, -7, -24, 18, 0, 51, -4, 59, 10, -20, 1, 14, -1, -15, 5, 13, -16, 57, 64, -11, -27, 32, 95, -58, -23, -83, -65, 52, 36, -19, -27, 80, 36, -2, -32, -59, -47, 13, -33, 20, 49, 28, 1, 0, -9, 41, -6, -44, 19, -28, -48, -38, -34, -95, 34, -27, 47, -11, 34, -15, -115, -44, -8, -50, 51, -21, -23, 2, 20, 43, -23, 1, 4, 21, -9, -18, -22, -44, -26, -35, 8, 42, 22, 28, 14, 5, -6, -35, 18, 23, -41, -58, -7, 16, -59, 0, 11, -33, 25, -32, -75, 23, 19, -20, 33, 26, 9, 23, -41, 29, 10, 40, -14, 44, 11, -11, 20, 22, -5, -34, -39, -20, 2, 9, 46, 25, 69, 35, -26, -12, 10, 21, 21, -17, 63, 5, 25, -4, 9, 53, 18, -6, -13, -43, -8, -5, -3, 8, 18, -18, 28, -11, -3, 7, 4, -2, 8, -18, -53, 29, 24, 12, 2, -8, -25, -9, -19, 27, -29, -92, 4, 6, 61, 14, -55, -5, 30, 5, 1, -33, 15, 8, -34, -21, -8, 58, 11, -30, 4, 12, 10, -61, -18, -6, 12, -2, 10, 19, 36, -35, 71, 5, 59, 15, -8, -22, -7, -54, 59, 17, -14, 17, -37, 14, -20, -14, 17, -18, -29, 1, 16, 5, -19, 43, 12, -19, 15, 18, 35, -5, -37, -15, -14, 27, -10, 5, -3, 72, -35, -26, 32, 3, 56, -11, 21, -4, 0, -12, 20, 38, -2, -19, 34, -2, 36, -3, 7, -11, 3, 16, -16, 28, -21, 9, 3, 28, -21, 7, 53, -23, -2, 19, -20, 36, 7, 70, -11, -15, 21, -9, 22, -26, 29, 24, -1, -13, -31, 19, 66, -41, -6, 30, -47, -1, 22, 2, 25, -19, 49, 25, -12, -19, 73, -24, 35, -33, 7, 29, 45, -11, -43, -2, 8, -28, 44, -20, 21, 9, -3, -55, 17, -38, -23, 2, 22, -9, -6, -3, 15}

#define TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_GRU_11_GRU_CELL_11_BIAS_0 {127, -4, 109, 117, 41, 85, 104, 125, 57, 60, 91, 92, -44, -43, 14, -1, -20, -6, 40, -29, 32, 30, -32, 26, 34, 7, 16, 32, 1, 11, 6, 4, -22, 27, -12, 21, 127, -4, 109, 117, 41, 85, 104, 125, 57, 60, 91, 92, -44, -43, 14, -1, -20, -6, 40, -29, 32, 30, -32, 26, 29, 10, 11, 29, -11, 16, 7, 18, -36, 30, -20, 15}

#define TENSOR_GRU_11_GRU_CELL_11_BIAS_0_DEC_BITS {7}

#define GRU_11_BIAS_LSHIFT {5}

#define GRU_11_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_3_KERNEL_0 {44, 13, -80, 43, -8, 13, 45, 45, 30, -1, -51, 10, -22, -9, -98, 56, 71, 49, 6, 47, -32, -48, -64, -32, -74, -25, 62, -67, -8, 7, 20, -49, -18, 83, 59, 10, -80, -39, -57, 17, -41, 69, 66, 82, 29, -53, -38, -63, -86, 49, 0, 25, 33, 25, -57, 42, 87, 26, 9, 35, 6, 32, -81, 28, -26, 81, 44, 28, 7, 16, -41, -27}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_3_BIAS_0 {-74, -87, -38, -17, 24, 100}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {9}

#define DENSE_3_BIAS_LSHIFT {4}

#define DENSE_3_OUTPUT_RSHIFT {9}


/* output q format for each layer */
#define GRU_9_INPUT_OUTPUT_DEC 9
#define GRU_9_INPUT_OUTPUT_OFFSET 0
#define GRU_9_OUTPUT_DEC 7
#define GRU_9_OUTPUT_OFFSET 0
#define GRU_10_OUTPUT_DEC 7
#define GRU_10_OUTPUT_OFFSET 0
#define GRU_11_OUTPUT_DEC 7
#define GRU_11_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 4
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t gru_9_input_config = {
    .super = {.name = "gru_9_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_9_gru_cell_9_kernel_0_data[] = TENSOR_GRU_9_GRU_CELL_9_KERNEL_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_kernel_0_dim[] = {3, 60};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_kernel_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_kernel_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_data[] = TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_dim[] = {20, 60};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_9_gru_cell_9_bias_0_data[] = TENSOR_GRU_9_GRU_CELL_9_BIAS_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_bias_0_dim[] = {2, 60};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_bias_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_bias_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_9_gru_cell_config = {
    .super = {.name = "gru_9"},
    .weights = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 20
};

const nnom_rnn_config_t gru_9_config = {
    .super = {.name = "gru_9"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_10_gru_cell_10_kernel_0_data[] = TENSOR_GRU_10_GRU_CELL_10_KERNEL_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_kernel_0_dim[] = {20, 48};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_kernel_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_kernel_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_data[] = TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_dim[] = {16, 48};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_10_gru_cell_10_bias_0_data[] = TENSOR_GRU_10_GRU_CELL_10_BIAS_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_bias_0_dim[] = {2, 48};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_bias_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_bias_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_10_gru_cell_config = {
    .super = {.name = "gru_10"},
    .weights = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 16
};

const nnom_rnn_config_t gru_10_config = {
    .super = {.name = "gru_10"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_11_gru_cell_11_kernel_0_data[] = TENSOR_GRU_11_GRU_CELL_11_KERNEL_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_kernel_0_dim[] = {16, 36};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_kernel_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_kernel_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_data[] = TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_dim[] = {12, 36};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_11_gru_cell_11_bias_0_data[] = TENSOR_GRU_11_GRU_CELL_11_BIAS_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_bias_0_dim[] = {2, 36};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_bias_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_bias_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_11_gru_cell_config = {
    .super = {.name = "gru_11"},
    .weights = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 12
};

const nnom_rnn_config_t gru_11_config = {
    .super = {.name = "gru_11"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {12, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_9_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_9_gru_cell_config), &gru_9_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_10_gru_cell_config), &gru_10_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_11_gru_cell_config), &gru_11_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_3_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_3_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_23_NNOM_H