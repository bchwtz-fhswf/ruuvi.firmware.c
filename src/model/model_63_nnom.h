#ifndef MODEL_63_NNOM_H
#define MODEL_63_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_63_nnom
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
#define APP_ACTIVITY_RECOGNITION_FFT_SKIP_IMAG (1)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_9_KERNEL_0 {0, 3, 15, -5, 0, -5, 10, -32, -7, -50, -6, -72, 27, -9, -68, -11, -8, -3, 3, -1, -3, 3, 2, 5, -6, 10, -1, 5, 5, 5, -6, -66, 7, 66, -7, -2, -5, -6, 4, 71, 0, 20, 13, 1, -5, -4, -3, 5, -8, -17, 5, 13, -1, -6, -4, 29, 10, 34, -7, -45, 58, 38, 30, 7, 3, 9, 19, 3, 13, -6, 0, 16, -25, -68, 11, -6, -6, 3, -3, -3, -3, 1, 7, 6, -33, 24, 49, -34, -1, -4, 1, 7, -8, 13, 12, -23, 0, 7, -2, 6, 7, -3, 4, -1, 15, 15, 19, 54, -4, 0, 6, 6, 6, 4, -12, 10, 29, -54, -22, 39, 3, 12, 6, 7, 14, 1, -8, 23, -5, 58, -8, 18, -3, -9, -7, 9, -21, 9, -18, 16, 53, -20, 15, -1, 46, -37, -6, 7, -6, 5, -1, 1, -3, 4, 6, -17, 6, 5, 3, -3, 15, 7, 1, -5, -74, -7, 48, -3, -5, -1, 7, -3, -20, -14, 61, 26, -35, -21, -1, 6, -36, 51, -40, 21, -25, 0, -14, -4, 9, 7, 4, 1}

#define TENSOR_CONV2D_9_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_9_BIAS_0 {-10, -84, -7, -88, 11, -83, -68, -71, 19, -22, -2, -4, -4, -6, -7, -74}

#define TENSOR_CONV2D_9_BIAS_0_DEC_BITS {5}

#define CONV2D_9_BIAS_LSHIFT {4}

#define CONV2D_9_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_10_KERNEL_0 {24, -5, -7, -2, 10, 36, -20, -25, -2, 1, 9, 4, 17, 3, -1, 18, 2, -36, -2, -19, -9, 25, 11, -15, -8, -31, 12, -5, -7, -1, 4, 20, 14, 17, -11, 15, -17, -7, 13, -11, 4, 8, 0, -8, -19, -12, -4, 8, -20, -6, -22, -24, -5, 5, 20, -6, 1, -20, 6, -12, 15, 26, 1, -9, -13, 1, 0, 23, -5, -17, -19, -2, 4, 11, -2, -36, -25, -20, -29, 15, -9, 11, -33, -2, -7, 7, -16, -17, 8, -40, -31, 8, -11, -19, -41, 10, -24, -1, 7, -3, 27, 35, -3, 0, 7, 0, 16, -41, -3, -48, -26, 28, -7, -5, -29, -13, -17, 9, 10, -5, 16, -46, -31, 5, -17, -36, -15, -7, -13, 7, 2, 13, -2, -10, -8, 7, -4, 0, -6, -3, 5, 13, 2, -8, 11, 3, 6, 15, 10, 8, 5, 15, -3, 19, 2, -4, -5, 7, -1, -4, 3, -16, 0, -7, 11, -15, 12, -19, 1, 14, 7, 1, 8, 16, 10, 2, 3, -13, 13, -7, 10, -3, 0, 8, -1, 10, 8, -1, -3, 2, 2, -5, -3, -3, -10, -8, -3, -8, -3, 0, 2, -3, -10, -10, 9, -3, 1, -13, -3, 0, -2, 15, 11, 12, 12, 15, 13, 6, -4, -15, 7, -7, -3, 1, 6, -25, 1, -27, 2, -7, 2, -16, 9, 5, 3, -1, -1, 1, 0, -15, 20, -22, 12, -18, 6, -1, 2, 1, 4, 4, 14, 7, 3, 6, 5, -16, 20, -2, -3, -1, 7, -5, 32, 11, -2, 28, -24, -15, -74, -79, -33, 42, -10, -34, -15, -24, 3, -6, -43, -26, 2, -24, -18, -22, -22, 1, -7, 19, 0, -35, 10, 25, 10, 9, -35, -43, 9, -33, 20, -114, -58, -88, -41, -27, 3, -41, -47, -10, -1, -12, -44, 29, 13, 8, -40, 6, 5, -28, -26, -59, 7, -34, 12, 14, -1, 2, -16, -51, 9, 17, -4, -33, -40, -57, 21, -22, 11, 20, 3, -9, -6, -15, -28, -9, -2, -58, -22, -19, -46, -8, 24, -54, -7, -18, -11, 9, 4, -10, -20, -22, 13, -61, 9, -103, -118, -69, -19, 10, -27, -67, -69, 5, -1, 5, -50, 5, 1, -72, -14, -33, 12, 5, -41, -43, 10, 10, -7, 8, 4, 15, 19, 11, 11, -4, 17, 0, 14, 10, -18, 25, 11, 1, -7, 18, 4, 17, 27, 2, 9, 9, 13, 0, 23, -4, -9, 26, 21, -41, 9, -20, 1, -6, -8, -15, 0, -6, 17, 4, -8, -6, 1, -20, 3, -23, 10, -15, -12, -17, -1, -41, 0, -4, -4, 10, -3, -14, 0, -13, 13, 3, -3, -7, -18, -9, -6, -11, 7, -36, 4, 10, 0, -12, 1, 1, 4, -1, -1, 12, -12, -16, -7, -4, 5, -35, 3, 8, -2, -6, 3, -3, 6, -9, -6, -21, -3, -17, -17, -9, -3, -2, 12, 1, -12, 2, -20, -4, 10, -2, -3, -26, -1, -4, -23, -25, -5, 1, 14, 4, -6, 8, -17, -15, 8, -6, 2, -14, 16, -34, -14, -14, 19, 0, 1, 5, 1, 6, 2, -23, 9, -15, 2, -14, 6, -11, -32, 0, 16, 12, 11, -5, 4, 4, 6, -31, 5, -9, 5, -30, 18, -23, -1, -25, 1, 4, 5, 7, 7, 21, 6, -17, 5, -13, 14, -18, 16, -4, -14, -9, 10, 17, 9, 4, 2, 11, 2, -7, -2, -2, -4, 2, 8, -10, -18, -15, 5, 3, -1, -6, -9, -9, 1, -19, -1, -1, 0, -2, 7, -15, -9, 4, 2, 6, 4, 7, 6, -8, 2, -9, -11, -34, 3, -30, -10, -14, -12, -16, -11, -10, -13, 0, -4, -4, 1, -12, -5, -40, 7, -27, -13, -4, 2, -22, -7, -8, 0, 5, 15, 4, 8, 0, 3, -17, -12, 2, -3, 8, 20, -14, -8, -3, -2, -4, 3, -4, -10, 14, -1, -24, -11, -18, -3, 11, 22, -20, 6, 4, 5, 1, 10, -8, -15, 25, 0, -59, -17, -4, -2, -20, -11, 0, 2, -20, -20, -29, 11, -27, -19, -4, 7, -66, -29, -53, -12, 0, -30, -93, 9, -36, -10, -13, -14, -21, -27, -10, -4, -21, -8, -7, 10, -15, -6, -21, -4, 1, -4, 2, -3, 5, -3, -22, 2, -19, -9, -24, 15, -16, -10, 8, 1, -1, 2, -4, -3, 0, -3, -18, -4, 1, -1, 18, 9, -13, -15, -2, 4, 1, -6, 0, 5, 14, -2, -4, 20, 16, 11, 11, 14, 11, -12, 0, 26, 12, 5, 7, 1, 13, 14, -9, 3, -12, 1, -3, -5, -20, -21, -20, -9, 8, 13, 7, 7, 18, 14, -24, -7, 13, 15, -9, -2, -18, -15, -8, -10, 7, 16, 15, 14, 9, 6, 4, -1, -20, -6, 3, -15, -17, 6, -8, -18, 1, 5, 1, 2, 1, 13, 0, -10, 2, -5, -3, -7, 7, -7, 1, 9, -25, -11, 6, 9, 3, -8, -2, -17, -5, -5, -18, -4, -4, 6, -5, 0, 10, -10, -13, -1, 11, -10, -5, -13, -34, -5, -40, -7, -4, -4, -19, 10, -4, 0, -9, 5, 0, 4, -11, 18, -43, 13, 3, 23, -30, -1, 13, 9, 17, 6, 13, -2, 9, 9, -16, -8, -37, -1, -38, -11, -30, -20, -22, 1, -1, -17, 2, 3, 12, -10, -24, 3, -10, 20, 12, 10, 12, 24, -4, -12, 6, 13, 22, 7, 3, 18, 18, 9, 9, 13, -32, -3, 12, -8, -3, -1, 11, 7, 18, 0, 15, 10, 13, -5, 7, -20, 8, 8, 18, 19, 13, 20, -21, 2, 2, 25, -6, -7, 10, 3, -9, -11, 12, 3, 13, 6, -3, 1, 4, 0, -3, 13, -4, -1, 13, 10, -12, -10, -55, -2, 3, 4, -6, -3, 6, 11, 8, 8, 7, -8, 1, -3, -24, -1, -37, -6, -14, -7, -19, -6, 0, 2, 1, 8, -8, -8, -10, -12, -15, -21, -12, -5, 1, -7, -5, 7, -2, -22, -25, -10, -9, -20, 9, -13, -21, -24, -5, -13, -26, -18, -31, 7, -28, -38, -35, -17, -19, -10, -1, 4, 23, 13, 15, 2, 22, 24, 22, 5, 10, 3, 18, 10, 3, 17, 19, -2, 10, 22, 12, 1, 1, 9, 21, -2, 6, 8, 10, 12, 2, 15, 13, -1, 16, 9, 9, -1, 14, -2, 11, -17, 7, -3, -1, 2, 13, 7, 1, -19, 10, 6, 6, -3, -4, -9, 6, -8, 6, -8, 0, 4, 9, 5, 5, -2, 16, -1, 7, -4, -4, -4, 3, -2, 9, 14, 0, 2, 3, 10, 5, -14, 13, -6, -6, -12, -7, 3, 1, -8, 0, -2, 4, 5, 4, -1, -5, 12, -12, -5, 0, -1, 4, -1, 1, 9, 4, 0, -10, -2, -11, 1, -1, -2, -5, -5, -7, -8, -5, -5, -2, 1, -1, -11, -1, 1, 3, -8, -3, -11, 19, -14, -13, -4, 6, -3, -10, -21, 8, -14, 6, -20, 6, -19, -6, 2, 10, 3, 24, 1, -29, -11, 1, 7, 5, -11, 5, -16, 7, -9, 1, -8, 5, -13, 5, 0, 23, 23, -21, -4, 5, 4, -2, 2, 14, -3, 2, 10, -30, 7, -33, 12, 1, 3, -1, -4, 21, 12, -4, -6, -2, 15, 26, -8, -16, -9, -19, 0, -6, -15, 0, 5, 3, -2, -28, 14, -22, 6, -4, -8, 2, -9, 10, -7, -21, 21, -31, -6, -12, -21, -5, -10, -3, 8, -9, -31, 16, 12, 9, 25, 5, -24, 32, -5, 19, 16, -15, 11, -31, 0, 9, -23, -1, -15, 14, -24, -16, 12, 10, -10, -27, -12, 24, 3, 9, 10, 4, 10, 3, -9, -1, -16, 11, 6, 1, 1, -2, 0, 8, -5, -15, -2, 13, -1, -6, -14, 10, -19, 3, 12, 0, -7, -10, -2, -1, 2, -1, -15, 5, -2, -12, -10, 5, -14, 21, 11, 8, -9, -5, 1, -8, -5, -10, -11, 14, -1, -8, -15, 17, -12, 3, 12, -5, -8, -20, -5, -6, 3, 0, -16, 8, 3, 19, -8, 13, -7, 20, 8, 5, -5, -2, -1, -3, 3, 1, -12, 13, 7, 12, -4, 27, -6, 22, 10, 7, 8, 13, 4, -3, -1, -2, -17, 12, 13, 16, 4, 11, 3, 24, 2, 5, 9, 4, 10, 12, -1, 19, 13, 13, 28, 22, 18, 32, 10, 3, 8, 10, 3, 7, 14, 9, 3, -5, 4, 9, 5, -23, -1, 12, -3, -8, -11, -21, 0, 8, 0, 4, -3, 0, -1, 0, 7, -3, -3, -15, 1, -18, -19, -23, -15, 2, -2, 4, -13, 4, -5, -7, 5, 32, -10, 28, 6, 18, 14, 12, 6, 0, 1, 0, 8, -1, 3, 18, 1, 21, 8, 26, 13, 5, 11, 13, 0, 9, 3, -4, 0, -4, -3, 10, -1, 2, 2, -13, 6, 17, 8, -2, -19, 1, 5, 7, 5, 8, 10, 4, 15, -3, 15, 5, 10, -2, -2, -8, -7, 12, 6, 4, 1, 7, 8, 3, -15, 21, -12, 12, -8, 7, -1, -1, -10, -5, -8, -16, 10, -5, -1, 11, -17, 11, -5, 16, 1, 3, 18, 5, -12, -6, 1, -7, 8, -10, 9, 15}

#define TENSOR_CONV2D_10_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_10_BIAS_0 {16, -20, 19, 35, 61, 30, 7, 10, -57, 12, -94, -67}

#define TENSOR_CONV2D_10_BIAS_0_DEC_BITS {5}

#define CONV2D_10_BIAS_LSHIFT {3}

#define CONV2D_10_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_11_KERNEL_0 {22, 7, -12, -29, -3, -19, 2, -26, -9, -8, -7, -5, 10, -13, -18, 15, -4, -5, -18, -2, -10, -13, -8, -4, -1, -14, 20, -6, 26, 16, -22, -8, -28, 8, -55, 15, -7, -7, 37, -4, -10, 20, 3, 1, -21, -13, -16, -38, -20, -31, 1, 8, 1, -21, -19, -12, -21, 18, -24, 10, -16, -7, 12, -27, -32, -12, -24, 7, -19, -8, -17, -22, 13, -12, 3, 27, -21, 14, 11, -16, -11, -6, -6, -56, -10, -25, 3, 11, -3, -44, -16, -1, 1, 17, 7, 15, 8, 12, -6, 4, -20, 22, 0, 4, 10, -8, 7, 21, 17, -6, 12, -20, -60, -3, -8, 8, -8, 0, 12, -3, 0, -1, -22, 9, 6, 0, 0, 8, 0, -6, -22, -7, -16, 9, -18, -18, 4, 0, 8, -11, -3, 6, -5, -1, 19, -29, 46, 19, 5, 19, -29, -16, 0, -39, -74, -9, -10, -20, 33, -3, 2, 16, 8, -27, 4, -23, -37, -77, 21, -24, 35, 10, 4, 19, 10, 9, -27, 10, -8, 8, 10, 19, 39, 14, 12, 16, 4, 5, -16, -4, 14, 10, 4, 12, -23, 6, -1, -19, -17, 0, 7, 21, 3, -17, -20, -15, -54, 21, 0, -5, 1, 8, -25, -23, -19, -35, 13, -26, 38, -14, -17, -7, 3, -11, -45, 13, -45, -38, -3, -39, 36, 12, 25, 7, -12, 20, -31, -7, -23, -43, -8, -53, 43, -7, 4, -3, -21, 7, -2, 12, 9, 4, 40, -32, 30, -5, -9, 5, -3, 0, -33, -1, -103, -74, -17, -11, -46, -15, 7, 17, -25, -44, -10, 2, -3, 15, -23, 13, -33, -24, -10, -13, 5, -22, 9, -19, 17, -8}

#define TENSOR_CONV2D_11_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_11_BIAS_0 {5, 58, -23, 3, -114, 127, 40, 33, 16, 17, 2, 23}

#define TENSOR_CONV2D_11_BIAS_0_DEC_BITS {6}

#define CONV2D_11_BIAS_LSHIFT {0}

#define CONV2D_11_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_3_KERNEL_0 {1, -33, -1, -13, -25, -39, -1, 19, -35, 12, -1, -12, -70, -43, -11, -22, 18, 9, 2, 3, -6, -16, -20, -8, -13, -24, -10, -16, 15, 11, -24, -14, -10, 2, -30, -24, -3, 3, -36, -22, -67, -31, -24, -6, 13, -70, -11, 1, -23, 24, -19, -5, 0, -17, 22, -4, -1, 27, 40, -22, -16, -30, 19, -10, -3, 3, -20, 6, 22, -39, 30, -7}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_3_BIAS_0 {-6, 20, 74, 11, -125, -58}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {6}

#define DENSE_3_BIAS_LSHIFT {0}

#define DENSE_3_OUTPUT_RSHIFT {3}


/* output q format for each layer */
#define CONV2D_9_INPUT_OUTPUT_DEC 0
#define CONV2D_9_INPUT_OUTPUT_OFFSET 0
#define CONV2D_9_OUTPUT_DEC 2
#define CONV2D_9_OUTPUT_OFFSET 0
#define RE_LU_9_OUTPUT_DEC 2
#define RE_LU_9_OUTPUT_OFFSET 0
#define MAX_POOLING2D_6_OUTPUT_DEC 2
#define MAX_POOLING2D_6_OUTPUT_OFFSET 0
#define CONV2D_10_OUTPUT_DEC -1
#define CONV2D_10_OUTPUT_OFFSET 0
#define RE_LU_10_OUTPUT_DEC -1
#define RE_LU_10_OUTPUT_OFFSET 0
#define MAX_POOLING2D_7_OUTPUT_DEC -1
#define MAX_POOLING2D_7_OUTPUT_OFFSET 0
#define CONV2D_11_OUTPUT_DEC 0
#define CONV2D_11_OUTPUT_OFFSET 0
#define RE_LU_11_OUTPUT_DEC 0
#define RE_LU_11_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_DEC 0
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 3
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3, 1};
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

const nnom_io_config_t conv2d_9_input_config = {
    .super = {.name = "conv2d_9_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_9_kernel_0_data[] = TENSOR_CONV2D_9_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_9_kernel_0_dim[] = {6, 2, 1, 16};
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
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_6_config = {
    .super = {.name = "max_pooling2d_6"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_10_kernel_0_data[] = TENSOR_CONV2D_10_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_10_kernel_0_dim[] = {4, 2, 16, 12};
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

const nnom_shape_data_t tensor_conv2d_10_bias_0_dim[] = {12};
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
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_7_config = {
    .super = {.name = "max_pooling2d_7"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_11_kernel_0_data[] = TENSOR_CONV2D_11_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_11_kernel_0_dim[] = {2, 1, 12, 12};
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

const nnom_shape_data_t tensor_conv2d_11_bias_0_dim[] = {12};
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
    .filter_size = 12,
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
	nnom_layer_t* layer[13];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_9_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_9_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_6_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_10_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_7_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_11_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_3_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_3_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_3_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_63_NNOM_H