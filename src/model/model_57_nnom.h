#ifndef MODEL_57_NNOM_H
#define MODEL_57_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_57_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (50)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (1536)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (160)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)
#define APP_ACTIVITY_RECOGNITION_FFT (1)
#define APP_ACTIVITY_RECOGNITION_FFT_SIZE (512)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_45_KERNEL_0 {5, -7, 9, 2, -12, 7, 1, -3, -8, 42, -51, -48, 64, 15, 73, 0, 6, -2, -38, 8, -5, 6, 8, 2, 2, -4, 4, -2, -23, -1, 93, 6, -69, 7, 34, -5, 3, 5, -1, 2, 5, 1, 20, -3, 10, 65, -7, 72, -9, 0, -2, -4, -26, -22, -35, -12, 17, 55, -5, 2, 0, 5, 0, 2, -3, -11, -18, 49, 1, -75, 3, 28, 15, 39, 13, 13, 8, 16, -1, 4, -8, 32, 27, 19, -4, -1, 2, -1, -2, 20, 19, 3, 67, -4, 25, 3, 41, 28, -39, 1, -5, 5, 2, 2, 4, 2, 8, 3, -41, 48, 35, -26, 5, 9, 13, 12, -7, 15, 13, -2, -49, -2, -63, 0, 1, -2, -8, 4, 1, -5, 8, 2, 5, 18, 8, 17, 6, -7, -6, 2, -4, -32, 35, -65, 2, 3, 11, -2, 79, -2, 9, -4, 10, -8, 9, -5, -22, 36, -4, 1, -2, -3, -9, 2, -12, -19, -46, 5, -44, -53, 33, 26, -3, -11, -6, 1, -3, 1, 4, 2, 14, -103, -14, -11, 0, -2, 0, -2, -3, -8, 1, -3}

#define TENSOR_CONV2D_45_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_45_BIAS_0 {-64, -4, 1, -66, -27, -6, -3, 14, -69, -4, -56, -49, -72, -63, -18, -31}

#define TENSOR_CONV2D_45_BIAS_0_DEC_BITS {5}

#define CONV2D_45_BIAS_LSHIFT {4}

#define CONV2D_45_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_46_KERNEL_0 {-3, 28, -31, -7, -2, -5, 3, -10, 20, 16, 20, -19, 6, -13, 20, -4, -23, -2, -36, -9, -28, -38, 36, -8, 6, 13, 10, 2, -20, 18, 19, 22, 11, -4, -9, 33, 4, -19, -13, 0, -4, -17, -28, 0, -14, -23, -44, -29, -13, -32, 6, 17, 6, -5, -3, 17, -49, -37, -39, 6, -11, -19, -60, -31, -29, 3, -22, -43, -11, -13, -53, -23, -32, -26, 2, -34, 25, -34, -28, -19, -33, -1, -24, -34, -26, -42, -41, -4, -11, -29, -18, -31, -17, -26, -29, -24, 37, 9, 25, 21, 2, 4, 21, 61, -9, 2, 19, 24, -9, 57, 23, 20, 31, -12, 7, 43, 24, 28, 17, 7, 6, -5, 15, 46, 3, 30, 12, 17, 21, 14, 2, 6, 12, 4, 5, -10, 25, 8, 17, -5, 46, 19, -6, -4, 2, -8, -19, 6, 12, 3, -9, 1, 7, 22, 7, 10, 36, 6, 16, 1, 33, -7, 1, 39, 8, 11, 11, -13, 8, -10, 20, 4, 21, 11, 23, 18, 31, 12, -8, 8, 0, 7, 3, -11, 35, 8, 14, 18, 23, 30, -9, 17, 18, 26, 22, 16, -5, 7, 4, -8, 19, -9, 25, -12, 33, 22, 5, 14, -12, -3, -4, 15, -14, 22, 9, -9, 9, -6, 10, -1, 21, 7, 11, 2, -5, -3, -3, 20, -9, -11, -3, 14, 12, 3, 13, 23, 31, 28, 2, 9, -4, -7, -19, 2, 0, 4, -4, -23, 33, 6, 1, 3, 34, 5, -4, 12, 10, -8, 18, 22, -6, -22, -2, -11, -2, -19, -25, 12, -45, -32, -17, -35, 24, -4, 5, 19, 9, 10, -43, 15, -40, 5, 15, -34, -60, -22, 45, 32, 2, -19, -12, 28, 7, -86, -35, -14, 20, 6, -14, -15, -13, -45, -7, 18, 39, -1, -54, -19, 16, -3, 0, -16, 15, -15, -2, 44, 17, -21, 41, 15, -29, -11, 13, -30, -26, -35, -23, -13, 0, -7, -11, -18, -56, -36, -28, -10, -5, -17, -9, -2, -43, -1, 0, -33, 5, 12, 5, 27, 22, 17, -24, -22, 4, -23, -29, 21, -2, -17, -35, -30, 4, -9, -18, 12, -49, -29, -7, -3, -16, -26, -18, 2, -12, -14, 1, -33, -11, 21, -8, -17, -10, 11, -30, -3, 27, -41, -8, 24, -2, 14, -5, 18, -10, -20, -13, 23, 31, -10, -52, -29, 37, -2, -1, 18, -16, 26, 7, -7, 9, 9, 21, -2, -11, -17, -54, -2, -34, -7, -16, 8, 3, -31, 7, -38, 15, -24, -20, -6, 32, 5, 6, -22, -44, 12, -23, -28, -43, -36, 17, -26, 42, 14, 20, -7, 25, 63, 17, -13, -20, -1, -37, 5, -19, -54, -17, -17, -19, 17, -14, -2, 0, -25, 3, 20, 2, -8, -21, 11, -75, -48, -2, -27, 11, 0, 10, 43, -19, -6, 2, 14, 11, 7, 29, -7, 11, 28, 22, 8, -4, 15, -27, -7, -27, 10, -28, -10, 10, -7, 3, -3, 33, 53, 0, 1, -12, -1, -17, -12, -8, -6, 6, -28, -21, -24, -21, -9, -8, 0, -10, -20, -21, -3, -1, -1, -8, 4, 3, -10, -13, 0, -10, 2, -21, 0, -16, -30, -1, -11, -19, -9, -10, -9, -9, -9, 9, 6, 0, 0, -21, 4, 8, 0, 6, 10, 2, -22, 12, -27, -16, -11, 8, 6, -14, -6, -16, -21, 8, -6, 3, -4, -11, -4, 14, -2, 8, -22, 6, -8, -13, -18, 0, 12, 6, -23, 12, 8, 10, 1, -12, -23, -18, -18, -6, -1, -24, -15, -21, 5, 1, -14, 7, -15, -7, -7, -4, -7, 1, -6, 8, -10, -21, 5, -17, -22, -14, -19, -23, 3, -25, 11, 0, -14, 10, 17, -9, -19, -3, -7, 2, 4, -20, 4, -9, -16, 1, -21, -22, -22, -21, 7, -2, 21, 14, 8, -13, 12, 24, -7, 42, 30, 18, 16, 3, 39, 25, 34, 15, 31, 24, -9, -12, 11, 9, 1, 36, 32, 23, 5, 17, 19, 31, 25, -2, -25, 26, 4, 15, 13, -4, 11, -30, 2, -22, 2, -26, 4, 13, 6, 18, -3, 17, -8, -21, 24, 0, 16, -10, 9, -19, -4, -32, 0, 8, 4, -33, 10, 12, -11, 18, 4, -8, 12, -17, -8, -10, -27, -4, -31, -22, -9, -38, 20, 29, -31, 18, 7, -8, 6, -5, 9, -29, -46, 8, -23, 13, -18, -4, -14, -10, -18, -18, 5, -3, -10, 0, -6, -10, -15, -40, 17, 6, 2, -14, -10, -17, -10, 2, -8, 13, -5, -5, 7, -16, 10, -13, -12, -4, -13, -93, -44, -13, 10, 28, -5, 4, 7, -8, -37, 18, 21, 15, 11, -15, -97, -14, 55, -44, -30, 11, -13, -25, -67, 5, -33, -74, -16, -20, -35, -41, -10, -8, 21, 3, 36, -1, -21, 20, 10, 9, 23, 27, -13, 9, -24, -5, 24, 1, 16, -12, -15, 10, -4, -28, -9, 20, -14, 19, -16, -77, 14, -16, -19, -13, -44, -40, 19, 27, -10, -59, 19, -30, -28, -10, -47, 27, -18, 15, 19, -32, -34, -2, -8, -40, -26, -44, 15, -15, 30, -3, -13, 23, -29, 2, -38, -21, -18, -29, -29, 36, -45, -22, 5, -14, -8, 13, 32, -10, 1, 11, 40, -20, 26, -31, 4, -63, -15, -6, 4, 19, 14, -36, -32, 19, 33, -22, 10, 8, -11, 4, 15, 0, 2, -23, -15, 6, -20, 9, -30, 10, 10, 0, 0, 17, -24, 0, -2, -12, -22, -16, 9, -2, -6, -15, 3, -18, -18, 12, -18, -11, -16, 8, -16, -11, -13, -15, -3, -4, -5, -23, 8, 7, 14, -26, -7, -22, -14, -22, 7, -1, -9, -7, -3, -3, 1, 5, 3, -4, -16, -8, -12, -2, 9, -24, 4, 3, -21, 2, -14, 13, -23, 14, -11, 10, 6, -23, -1, -9, -5, 0, -9, -12, 10, 7, -12, -21, -18, -7, -12, 11, 13, -19, -16, -22, 11, -8, 2, -21, -4, -19, 0, -8, -13, -9, -12, -18, 14, -8, -10, 9, -2, 3, 10, -11, -22, -20, -5, -7, 15, -19, -1, -1, 9, -22, -4, -50, 7, -8, -32, -29, -27, -8, -5, -16, 57, 25, 11, -37, -12, 14, -29, -104, -82, -25, -48, -66, -71, -40, -25, -26, -31, -9, -97, -72, -38, -33, 3, 29, 16, -37, 3, -29, -11, 11, 11, -100, 10, -14, -24, -52, 30, -46, -40, -83, -52, -31, -63, -54, -49, -26, -23, -88, -44, -102, -56, -55, -49, -62, -42, 27, -5, -2, 9, 25, 11, 26, 3, -47, 9, -19, -9, -21, -18, -29, -43, -64, -30, -34, -14, 58, -34, 24, -9, -58, -17, -25, -36, -38, -74, -38, -65, -72, 30, -33, 8, 47, 4, 17, 42, -54, -2, 9, 54, 6, 14, 0, -17, -10, -41, -38, -33, 6, -5, 8, -1, -37, -46, -23, 18, 0, -9, -76, 2, -4, 24, -8, -20, -9, -1, 20, 17, 25, 11, 48, 14, -1, 14, 9, -7, 10, 32, -1, -12, -1, -7, 0, 11, 3, -6, 37, 18, -22, -20, 16, 49, -57, 22, -8, -14, -16, 16, 16, -4, -23, 18, 8, -21, -67, -1, 29, 9, -41, 25, -12, -19, -16, -20, 30, 5, -18, 15, -11, -30, -23, 25, -10, 10, 0, -42, -20, -56, -39, -3, -3, -11, -6, -16, -29, -2, -57, -68, -9, -18, 4, -30, -13, -33, 11, -49, -12, -16, -24, -22, -52, -19, -3, -23, -49, -46, -9, 5, -22, -44, -2, 11, -12, 25, -71, -24, -16, -32, -38, -23, -52, 0, -43, -6, 14, -5, 20, -19, -17, 31, -5, -53, -25, 0, -43, -28, -56, -17, 18, -81, 1, 9, -82, -33, -28, 23, 16, -48, -15, -64, -1, -24, -43, -22, -3, -3, -17, -18, -93, -46, -5, -12, -16, -27, -20, -16, -6, -28, -15, -31, -14, -85, 17, 34, -91, -65, -54, 24, 9, -52, -44, -16, -37, -33, -77, -66, 15, 20, -23, -1, -120, -45, -24, -4, 42, -23, -42, 8, -20, -10, 3, -61, 41, -115, 10, -15, -48, -15, -32, 21, 5, -26, -15, -107, 27, 20, -54, -26, 14, 28, 31, -15, -34, -33, -1, 25, -16, -33, 9, 17, 8, 6, -10, -54, -30, -88, -29, -58, 30, -54, -96, 4, 19, -64, -84, -87, -37, 0, -63, -20, -84, -5, 3, 69, -12, -11, -15, 17, -6, -12, 7, 20, -26, 2, -6, -24, -5, 9, 1, -35, -12, 15, 24, 6, 19, 24, -3, -14, -55, 5, 7, 18, -12, 15, -1, -41, -16, -5, 4, -3, 11, 14, 20, -12, -22, 1, 12, 7, -11, -22, -8, -8, -23, 7, -3, -8, -57, -23, -50, 16, -23, -13, -12, -13, -6, -22, 10, -37, -34, -3, -12, -6, -39, -24, -24, -1, -29, -28, -5, -43, 11, -9, 31, 11, 29, 14, 0, 11, -17, 7, -30, 5, -49, 5, 10, 9, 14, 13, 22, -6, 8, 15, -9, 1, 9, 10, -29, -10, -26, -5, 0, -7, 7, 25, 18, 13, 16, 16, 10, -3, -17, 9, 0, 4, -8, 7, 8, -17, 22, 21, 28, 11, 24, 16, 26, 0, 1, 8, 2, 24, 15, 14, 15, -29}

#define TENSOR_CONV2D_46_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_46_BIAS_0 {-5, -115, -3, -19, -9, -13, 1, -15, 3, 38, 49, 64}

#define TENSOR_CONV2D_46_BIAS_0_DEC_BITS {6}

#define CONV2D_46_BIAS_LSHIFT {3}

#define CONV2D_46_OUTPUT_RSHIFT {10}

#define TENSOR_CONV2D_47_KERNEL_0 {-27, -4, 5, -22, 4, -12, -2, -19, -15, -28, 8, 4, -48, -9, 6, -2, 8, 5, 7, 8, 11, 20, 16, -45, 22, -5, 29, -1, -3, -9, 34, -15, 17, 4, 14, -18, 26, -3, 14, -15, -7, -1, 3, -10, 11, -11, -18, 4, -3, 10, -12, 0, 19, 6, 9, 21, -9, -1, 5, -28, 9, 5, -24, -9, -17, -7, 8, 8, 12, -5, -10, 1, -10, -10, 7, -18, 1, -26, 23, 1, -3, 22, 1, -28, -15, -6, -1, 15, -15, -22, 1, 14, -25, -9, -33, -8, -12, -12, 1, -36, 3, -14, -25, 2, 26, -21, 35, 11, -15, -26, -24, -13, 19, -9, 9, 21, 9, 31, 29, -10, 23, -46, -26, -9, 18, -17, 3, -11, -8, 11, -12, -3, -2, -19, 0, 15, -16, -3, 5, 7, 2, 4, -38, 9, -23, 1, -16, 12, 2, -12, 9, -4, -1, -16, -1, -8, 5, -10, -19, -5, 1, -7, -10, -18, 8, -1, -23, -25, 24, -7, 6, 10, -13, 9, -15, 17, 8, 20, -37, 3, -11, -14, 4, -1, 5, 4, 0, -3, 5, -9, -26, -25, -16, -4, 10, -39, 8, 14, -11, 20, 22, -3, -87, 5, -1, -6, -14, -14, -10, -12, 3, -18, -19, 15, -109, 6, 1, -22, -11, -11, -15, -2, -13, -16, -5, -5, -15, 1, 2, -18, 10, -19, 21, -26, -23, 19, -10, -12, 6, -6, 6, -31, -27, 2, 15, -8, -11, -18, 3, 22, 20, -12, -2, 7, 10, 21, 5, -29, 19, -21, 22, -9, 40, 13, 10, -35, 28, -21, -18, -30, 6, -17, 46, 18, 23, 2, 9, -1, 24, -12, -16, -25, -22, -21, 40, 7, 20, -15}

#define TENSOR_CONV2D_47_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_47_BIAS_0 {-5, 10, -75, -10, 31, 2, -10, 4, 34, -11, 28, 1}

#define TENSOR_CONV2D_47_BIAS_0_DEC_BITS {5}

#define CONV2D_47_BIAS_LSHIFT {0}

#define CONV2D_47_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_15_KERNEL_0 {-13, 4, 15, 13, -2, 2, -28, -39, 9, -15, -2, -31, -11, -20, -5, -26, 9, 57, 7, 9, -42, -52, -4, 24, 14, 7, -5, -19, -4, 15, -28, -5, -6, 2, 1, 2, 26, 21, -1, -3, 10, 2, 14, -23, 23, 11, 3, -15, 2, -32, -33, -22, 70, -47, 10, 19, -38, -15, 38, 54, -38, -5, -28, -13, -28, 22, -18, 2, 9, -6, 28, -8}

#define TENSOR_DENSE_15_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_15_BIAS_0 {-81, -5, 13, 53, 6, 0}

#define TENSOR_DENSE_15_BIAS_0_DEC_BITS {6}

#define DENSE_15_BIAS_LSHIFT {1}

#define DENSE_15_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_45_INPUT_OUTPUT_DEC 0
#define CONV2D_45_INPUT_OUTPUT_OFFSET 0
#define CONV2D_45_OUTPUT_DEC 2
#define CONV2D_45_OUTPUT_OFFSET 0
#define RE_LU_45_OUTPUT_DEC 2
#define RE_LU_45_OUTPUT_OFFSET 0
#define MAX_POOLING2D_30_OUTPUT_DEC 2
#define MAX_POOLING2D_30_OUTPUT_OFFSET 0
#define CONV2D_46_OUTPUT_DEC -1
#define CONV2D_46_OUTPUT_OFFSET 0
#define RE_LU_46_OUTPUT_DEC -1
#define RE_LU_46_OUTPUT_OFFSET 0
#define MAX_POOLING2D_31_OUTPUT_DEC -1
#define MAX_POOLING2D_31_OUTPUT_OFFSET 0
#define CONV2D_47_OUTPUT_DEC 1
#define CONV2D_47_OUTPUT_OFFSET 0
#define RE_LU_47_OUTPUT_DEC 1
#define RE_LU_47_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_15_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_15_OUTPUT_OFFSET 0
#define DENSE_15_OUTPUT_DEC 2
#define DENSE_15_OUTPUT_OFFSET 0
#define SOFTMAX_15_OUTPUT_DEC 7
#define SOFTMAX_15_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[384] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 6, 1};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {0};
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

const nnom_io_config_t conv2d_45_input_config = {
    .super = {.name = "conv2d_45_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_45_kernel_0_data[] = TENSOR_CONV2D_45_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_45_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_45_kernel_0_dec[] = TENSOR_CONV2D_45_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_45_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_45_kernel_0 = {
    .p_data = (void*)tensor_conv2d_45_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_45_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_45_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_45_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_45_bias_0_data[] = TENSOR_CONV2D_45_BIAS_0;

const nnom_shape_data_t tensor_conv2d_45_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_45_bias_0_dec[] = TENSOR_CONV2D_45_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_45_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_45_bias_0 = {
    .p_data = (void*)tensor_conv2d_45_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_45_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_45_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_45_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_45_output_shift[] = CONV2D_45_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_45_bias_shift[] = CONV2D_45_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_45_config = {
    .super = {.name = "conv2d_45"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_45_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_45_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_45_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_45_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_30_config = {
    .super = {.name = "max_pooling2d_30"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_46_kernel_0_data[] = TENSOR_CONV2D_46_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_46_kernel_0_dim[] = {4, 2, 16, 12};
const nnom_qformat_param_t tensor_conv2d_46_kernel_0_dec[] = TENSOR_CONV2D_46_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_46_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_46_kernel_0 = {
    .p_data = (void*)tensor_conv2d_46_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_46_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_46_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_46_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_46_bias_0_data[] = TENSOR_CONV2D_46_BIAS_0;

const nnom_shape_data_t tensor_conv2d_46_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_46_bias_0_dec[] = TENSOR_CONV2D_46_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_46_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_46_bias_0 = {
    .p_data = (void*)tensor_conv2d_46_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_46_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_46_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_46_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_46_output_shift[] = CONV2D_46_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_46_bias_shift[] = CONV2D_46_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_46_config = {
    .super = {.name = "conv2d_46"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_46_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_46_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_46_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_46_bias_shift, 
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_31_config = {
    .super = {.name = "max_pooling2d_31"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_47_kernel_0_data[] = TENSOR_CONV2D_47_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_47_kernel_0_dim[] = {2, 1, 12, 12};
const nnom_qformat_param_t tensor_conv2d_47_kernel_0_dec[] = TENSOR_CONV2D_47_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_47_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_47_kernel_0 = {
    .p_data = (void*)tensor_conv2d_47_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_47_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_47_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_47_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_47_bias_0_data[] = TENSOR_CONV2D_47_BIAS_0;

const nnom_shape_data_t tensor_conv2d_47_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_47_bias_0_dec[] = TENSOR_CONV2D_47_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_47_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_47_bias_0 = {
    .p_data = (void*)tensor_conv2d_47_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_47_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_47_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_47_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_47_output_shift[] = CONV2D_47_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_47_bias_shift[] = CONV2D_47_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_47_config = {
    .super = {.name = "conv2d_47"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_47_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_47_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_47_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_47_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_15_config = {
    .super = {.name = "global_max_pooling2d_15"},
    .output_shift = 0,
};
const int8_t tensor_dense_15_kernel_0_data[] = TENSOR_DENSE_15_KERNEL_0;

const nnom_shape_data_t tensor_dense_15_kernel_0_dim[] = {12, 6};
const nnom_qformat_param_t tensor_dense_15_kernel_0_dec[] = TENSOR_DENSE_15_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_15_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_15_kernel_0 = {
    .p_data = (void*)tensor_dense_15_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_15_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_15_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_15_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_15_bias_0_data[] = TENSOR_DENSE_15_BIAS_0;

const nnom_shape_data_t tensor_dense_15_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_15_bias_0_dec[] = TENSOR_DENSE_15_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_15_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_15_bias_0 = {
    .p_data = (void*)tensor_dense_15_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_15_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_15_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_15_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_15_output_shift[] = DENSE_15_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_15_bias_shift[] = DENSE_15_BIAS_LSHIFT;
const nnom_dense_config_t dense_15_config = {
    .super = {.name = "dense_15"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_15_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_15_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_15_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_15_bias_shift
};

const nnom_softmax_config_t softmax_15_config = {
    .super = {.name = "softmax_15"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_15_OUTPUT_DEC};
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
	nnom_layer_t* layer[13];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_45_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_45_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_30_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_46_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_31_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_47_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_15_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_15_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_15_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_57_NNOM_H