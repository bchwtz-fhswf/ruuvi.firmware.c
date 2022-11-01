#ifndef MODEL_55_NNOM_H
#define MODEL_55_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_55_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (100)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (768)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (256)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)
#define APP_ACTIVITY_RECOGNITION_FFT (1)
#define APP_ACTIVITY_RECOGNITION_FFT_SIZE (256)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_3_KERNEL_0 {20, -45, 12, -32, 10, 5, 3, -16, 3, -3, 2, 2, 3, 2, 8, 7, 3, 3, 8, -2, 11, 34, 18, 18, -22, 1, 20, -3, -12, 3, -8, -4, -6, -16, -17, -19, -17, 25, -21, 16, -4, -30, -6, -10, 6, -11, -5, 1, 38, -11, -67, 10, 17, 3, 6, 1, 7, 3, -2, -2, 22, 23, 18, 13, 10, 10, 3, 8, 3, 12, -12, 23, -1, -1, 2, 3, 0, -6, -3, -9, -14, -73, 2, 3, -1, 0, 2, 0, -7, 4, 28, -17, 55, -14, -1, 0, 2, 2, 5, 4, 0, -2, 5, 6, 11, 12, -10, -50, -3, 3, 0, 4, -4, -2, -5, 30, -4, 74, 2, -1, -23, 6, -30, 6, -15, 10, -17, -12, -14, -13, 0, 0, 13, 6, -10, 4, -20, 6, 32, 9, 8, 6, 4, 5, 7, 9, -21, -3, -8, -1, 2, -2, 1, -5, 42, -17, 4, 3, 2, -14, 3, -11, -7, -6, 2, -2, 2, 50, -2, -5, 2, -6, 0, -4, 3, -6, -9, 5, -55, -2, -8, -28, 12, 40, -8, -4, -5, 2, 1, 1, 6, -1}

#define TENSOR_CONV2D_3_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_3_BIAS_0 {-73, -119, 55, -120, -20, -4, -56, -51, -48, -65, 37, 58, -6, -5, -12, -79}

#define TENSOR_CONV2D_3_BIAS_0_DEC_BITS {5}

#define CONV2D_3_BIAS_LSHIFT {3}

#define CONV2D_3_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_4_KERNEL_0 {-44, -12, -8, -17, -22, -13, -3, -4, 7, -2, 4, 6, -9, -14, -13, 10, -11, 4, -3, -28, -13, -4, 0, 4, -5, -1, 8, 1, 0, -2, -4, -34, -6, -26, 1, 11, -11, -3, -15, -3, -24, 5, 5, -1, -21, -15, -27, -11, 4, 6, -2, -10, -1, 8, 7, 2, -5, 3, 10, 3, -7, -6, -5, -13, 2, -38, 10, -4, -3, -9, 8, -35, -12, -33, 5, 15, -18, -10, -10, 7, 3, -4, 3, -16, -2, 2, -15, -8, -1, -15, -1, 4, -2, -2, -7, -9, -8, -3, 4, 25, -8, -4, 2, -7, -7, 4, -3, 13, 2, 6, 3, -3, -3, -5, 7, -17, -19, 6, -2, -2, 3, -4, -3, 0, 1, 4, 6, 3, -3, 7, 2, 1, 4, 3, -19, -27, 6, -14, -7, -9, 4, 8, 4, 1, -9, -11, 2, -5, 4, -4, -33, -13, 13, -4, -4, -15, 3, 4, 5, -1, -2, 3, -4, 1, -12, -7, -5, -6, 2, -9, -8, -2, 0, -2, 1, -20, 0, 3, 0, 3, -6, 7, 7, 1, -17, -23, 2, 3, -1, 10, 5, -8, 5, 4, 1, 7, 2, 2, 0, 5, 1, 4, -10, 1, 2, -3, -1, 6, 4, 16, 1, 7, 8, -4, 0, -2, -2, 10, -4, 0, 0, -5, 0, 6, -2, -1, 2, 6, 4, -2, -12, -6, -9, -11, -1, -7, -7, -4, -7, 1, 12, 2, -2, 7, 8, -2, -15, -2, -8, -22, -1, -4, -7, -20, -3, 10, -6, 5, 0, 4, 4, -7, 6, 5, 1, 8, -9, -3, -7, -8, -3, 4, -4, 1, -5, -2, 6, -8, 6, 1, -2, 5, -6, -6, -3, 1, -4, 3, -5, 1, -2, -4, 9, -10, -15, -19, -3, -11, -12, -11, 1, -1, -6, 7, -6, -3, -8, -5, 7, -9, -13, -15, -8, -15, -5, -5, -3, -7, -6, 4, 6, 8, 3, 2, 0, -1, 8, 8, 2, 8, 2, -6, 7, 0, 9, 3, -3, 9, 3, 4, -2, 3, 8, 6, 1, 9, -1, -2, 1, -3, -4, 2, 3, -1, -11, 3, -2, -3, 3, 1, 8, 2, 2, 2, 5, 2, 6, -3, 1, -3, -10, 3, -1, -6, 4, 0, 1, 4, 1, -4, -3, -1, -4, -3, -3, -2, -6, -1, -7, -4, 2, -5, 1, -4, -5, -3, -2, -4, 2, -7, -2, -4, -1, -4, 0, 1, 3, 0, -5, -5, 1, 1, -1, -1, -1, -4, 1, -5, 2, 2, 1, -5, -3, -1, -7, -4, -2, -2, 2, 0, 1, -4, -2, 1, 2, -3, -5, -1, 0, -6, 0, 2, 1, -3, -2, 1, -1, -3, -4, -1, -7, -1, -3, -2, -1, 3, 2, -5, -1, 1, -3, 1, -4, 1, -2, 1, -5, 4, -3, -7, -5, -3, -2, 2, -4, -7, -2, 2, -7, -3, 3, 1, -4, 1, -1, -1, -4, -4, -7, -1, -3, -1, -3, -5, -1, -1, -4, -5, -7, -5, 2, 1, 2, -3, -5, -5, 1, -6, -5, -7, 2, -4, 0, -34, -13, -27, -11, -8, -26, -28, -42, -49, 4, 5, -16, -27, -35, -24, 12, -5, 5, 16, -4, 14, -13, -5, 2, -8, -4, 5, 10, 4, 1, 10, 9, -35, -12, -2, -11, -7, -91, -61, -20, -81, 7, -2, -25, -12, -25, -53, 3, -11, 4, -7, -9, -12, 6, -45, 0, -29, 0, -18, -3, -3, 7, -14, -52, -3, 4, -13, -39, -55, 18, -55, -22, 24, 4, 7, 11, -18, -2, -33, -19, 2, -8, -31, -8, 4, -11, -4, 5, -8, 1, 1, 8, 6, -11, -24, 8, -24, -6, -47, -26, -16, 7, -11, 9, 4, 3, -6, -23, 10, -19, -18, 0, -2, -3, -18, -13, -1, 4, 6, -1, 2, -5, 4, -1, 3, 1, -10, -3, 8, 4, 20, 1, 1, 0, 3, -2, 6, 18, -4, -8, 0, -14, 10, -15, 9, -10, -16, 3, -13, -1, 5, 2, -2, 1, -3, -8, -8, 7, -13, 3, 10, -48, 14, -10, 5, -22, 8, -7, 1, 4, 8, 10, 2, 7, 15, 2, 8, -10, -5, -11, 9, -12, -2, 6, -14, 3, -5, 3, -5, 3, -20, 1, 10, 11, -7, 7, 1, 2, 7, 1, 2, -18, -1, 8, -10, -4, 5, -9, 10, -1, 1, 1, -5, 0, -4, -14, -6, 0, -8, -7, -4, -16, 5, 25, 3, -16, -10, -3, 8, -3, 0, 4, 2, 24, -13, -6, -3, 4, -5, -5, -10, -14, 5, 6, -5, -8, -8, -2, -14, -20, -10, -9, -11, 12, -9, -2, -2, -6, -6, -3, -6, -2, 4, -3, 1, -2, 3, -5, -3, -2, -4, 2, -6, -2, -7, -5, 1, -2, -2, -3, -4, -3, -4, -5, -2, -2, 0, -1, -2, -6, -5, -1, -3, -1, -2, -3, 4, -1, -7, 3, -5, 3, -3, -1, 3, -3, 0, -4, 0, -5, 3, 1, -3, -2, -4, -6, 3, -5, -6, -4, -3, -4, 2, -4, -6, 0, -1, 2, -5, -1, -2, -4, -7, 1, -3, 0, -2, 0, -6, 0, 1, -3, -5, -1, 0, -7, 2, -5, -6, -6, -2, -6, -6, -7, -2, 1, -2, 2, -2, 1, 2, 0, -2, 1, -1, 3, -4, -3, -5, 1, -7, -6, 4, -1, 2, -3, -6, 1, -5, 0, 2, -3, -4, 4, 6, -3, 7, 3, -6, 2, 8, 3, 3, -2, 0, 0, 2, 4, 2, 3, 8, 1, 2, 1, -2, 3, 0, 0, 4, -4, 1, -3, -3, 2, 4, 5, 0, -4, 6, 2, -3, 2, -2, -1, 2, 4, -3, -1, -1, 2, 2, 6, 7, -6, 6, 2, 0, 0, -3, -3, 2, -5, -4, -1, -6, -7, 3, 4, 3, -6, 8, 4, -1, 6, 6, -1, 5, 3, -14, -6, -5, 0, 6, 4, -1, -6, 3, 3, -4, 3, -2, -5, 6, -7, -13, -5, -6, -8, 3, 16, 10, -6, 4, -5, 1, 4, 6, 5, 3, 3, -10, 10, 7, 10, -1, 1, 4, -7, 3, -6, 3, 5, -1, 7, 3, -8, -10, -1, 3, 2, -2, -5, -2, -1, 0, 1, -3, -5, -2, -3, 0, -4, 1, -1, -5, 2, 1, -4, -2, -2, -5, 2, 1, 2, -2, 2, 1, -5, 1, -4, -1, -5, -5, 0, 2, 1, 0, -1, -3, -4, -8, -1, 3, -4, -6, -4, -3, -6, -1, -2, -2, 3, -4, -4, -2, -2, -7, -3, -8, 2, -3, 2, 2, 0, 0, -5, -3, 1, -5, -3, -1, 0, 4, -1, 2, -1, -5, -3, -2, -4, -7, -6, 3, -3, -6, 3, -7, -6, -4, -3, -1, 3, 0, 0, -2, -4, 1, -3, -2, -1, -4, -4, -7, -1, -6, -6, -4, -6, -6, -6, 1, 1, 1, -7, 2, -2, 1, -7, -3, -5, -3, -2, -6, -6, -3, 1, -5, -1, -6, 3, 8, -10, 9, -10, -2, 3, 0, 1, -3, -6, 8, 5, 3, 8, -13, -5, -2, -11, -1, -15, -5, 4, 0, -12, -3, -11, -2, -5, -5, 3, -8, -2, 2, 13, 4, 17, 1, 5, 10, 0, 7, -13, -2, 2, 2, 2, 12, 0, -4, -5, 0, 6, -3, -7, -11, -5, -4, -1, -9, -2, 3, -6, 12, 0, -5, -14, 12, 2, -10, 1, -4, 0, -4, -8, -15, 19, 8, 10, 7, 0, 6, -11, 1, -10, -4, -6, 10, -2, 7, -11, -19, 4, -1, -3, -4, 8, 1, -3, -17, -29, 2, -12, -8, 2, -2, 3, -15, 1, 10, 3, -34, -1, -1, 0, -1, -30, 2, -7, -12, 5, -9, -5, -11, 0, 8, 3, -18, 2, 3, 0, -5, -1, -4, -3, -5, -3, -1, -2, -6, 2, -6, 1, 0, -2, -3, -7, -7, 1, -5, 0, -3, -4, 1, -5, -5, 2, -3, -2, 1, 1, -3, -3, 1, 0, -2, 1, -3, -2, -1, -2, -3, -2, -1, 1, 1, -3, -1, -8, -5, -2, -4, -3, -4, 3, -1, -2, -1, 0, -5, -6, -1, 3, 2, 2, -4, -4, -2, -1, -3, -1, 2, -6, 1, -3, -4, 1, -1, -4, -6, -3, 0, -1, -3, -3, -3, -7, 1, -3, -6, -3, -5, -6, -5, -3, -4, -3, 3, -3, -7, -1, 2, -3, -6, -8, 1, -7, 0, 1, -4, -6, 2, 2, -1, -4, -4, 0, 1, -4, 2, 1, -3, 2, 0, -3, -1, -7, -38, -13, -18, -2, -10, -19, -2, -6, -25, -6, -19, -5, 7, -1, -7, 13, 11, -2, 16, -9, 11, 0, -6, -7, 0, -5, 10, -2, -22, 2, -16, -25, 1, -3, -7, -16, 0, -17, -6, 4, -14, -3, -9, 7, 2, 7, 8, 9, 9, 5, 10, 3, 6, 33, 2, 2, 1, -6, 6, -5, -1, 0, -30, 4, 9, 13, 1, -16, 4, -1, 8, -13, 5, 1, -5, -13, -5, -13, 0, 1, 4, -3, -40, 6, -5, 2, -2, 6, 14, 1, 3, -5, -17, -4, -8, 1, -7, -6, 1, -4, 1, -18, -5, -4, -17, -6, 1, -2, -2, 5, -1, -19, 9, -5, 7, 0, 2, -2, 1, 4, 7, 0, -6, -2, 3, -7, -11}

#define TENSOR_CONV2D_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_4_BIAS_0 {37, 15, 5, -3, 5, -57, -9, -95, -4, -77, -7, 1}

#define TENSOR_CONV2D_4_BIAS_0_DEC_BITS {5}

#define CONV2D_4_BIAS_LSHIFT {1}

#define CONV2D_4_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_5_KERNEL_0 {-34, -41, -11, 3, -5, -1, 6, 2, -2, 1, 8, -2, -44, -4, -10, 2, -10, -4, -2, 7, 7, -5, -17, 1, 24, -7, 2, -19, 29, -11, -18, -4, -13, 10, -1, 13, 27, 3, -8, -1, 23, 8, 3, -1, 18, -2, 4, -46, -19, 3, 0, -4, -11, 6, 14, 7, 2, -2, -3, -5, -12, 1, 1, 17, -12, -7, -4, -5, -4, -15, 6, -1, -43, -3, 15, 9, 25, -8, -5, -45, 19, -46, -14, 3, 28, -12, -7, 20, -4, -2, -19, -9, 0, 1, -7, -7, 19, -2, -77, 14, -49, -31, 7, -54, -6, -1, 16, -15, -21, -40, -52, 16, 16, -38, 1, -4, -12, -33, 7, -5, 16, -8, -80, 8, -93, -39, -19, 3, -8, -32, -20, -10, 18, -124, 2, 6, -33, -24, -13, 4, -17, 5, -2, -89, -16, 0, -16, -1, -15, -11, -12, -58, 14, -47, -16, -19, 28, -13, 2, 21, -5, -4, -17, -14, 6, -3, -22, -56, 18, -11, 0, -9, 32, 0, -7, -7, -17, -14, 6, 6, 35, 5, 7, -20, 39, 1, 13, -34, -11, -4, 16, -1, -67, -16, 0, -11, -1, -7, 14, 0, -25, 9, -5, -16, -51, 0, -7, -20, -27, 15, 13, -4, 20, -28, 22, -7, 1, 11, 2, 21, 21, -5, -8, -12, 16, 11, -13, -3, -8, -41, -15, 4, 12, -2, 21, 0, 8, 0, -12, -16, 21, -7, 1, -7, -13, -14, 17, -43, 13, -4, -6, -21, -25, -2, 12, 6, -25, 1, 0, -3, 10, -10, 1, -32, -17, -102, 1, 20, -3, -31, 18, -5, -8, 2, 12, -16, -8, 4, -7, 4, -11, -3, -24, -3, -6, -13, 14, 9}

#define TENSOR_CONV2D_5_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_5_BIAS_0 {-84, -34, -125, -1, -10, -89, -15, 24, -6, 46, 7, 21}

#define TENSOR_CONV2D_5_BIAS_0_DEC_BITS {6}

#define CONV2D_5_BIAS_LSHIFT {0}

#define CONV2D_5_OUTPUT_RSHIFT {3}

#define TENSOR_DENSE_1_KERNEL_0 {31, 31, 32, 28, 1, -22, -22, -51, 2, -9, 36, -17, -19, -26, -8, -8, -1, 9, -22, 22, -13, -13, -16, 8, 17, 12, -29, -8, -24, -19, -11, -11, 35, 22, -21, 6, 34, 24, -1, 0, -23, -12, -4, -22, 13, 18, -7, -1, -39, 27, -40, -9, -58, -40, -14, 14, -4, -6, -58, -69, -15, -29, 12, 2, -11, -23, -11, 8, 19, 22, -14, -7}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_1_BIAS_0 {-52, -31, 23, 9, 67, -15}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {6}

#define DENSE_1_BIAS_LSHIFT {1}

#define DENSE_1_OUTPUT_RSHIFT {4}


/* output q format for each layer */
#define CONV2D_3_INPUT_OUTPUT_DEC 0
#define CONV2D_3_INPUT_OUTPUT_OFFSET 0
#define CONV2D_3_OUTPUT_DEC 1
#define CONV2D_3_OUTPUT_OFFSET 0
#define RE_LU_3_OUTPUT_DEC 1
#define RE_LU_3_OUTPUT_OFFSET 0
#define MAX_POOLING2D_2_OUTPUT_DEC 1
#define MAX_POOLING2D_2_OUTPUT_OFFSET 0
#define CONV2D_4_OUTPUT_DEC -2
#define CONV2D_4_OUTPUT_OFFSET 0
#define RE_LU_4_OUTPUT_DEC -2
#define RE_LU_4_OUTPUT_OFFSET 0
#define MAX_POOLING2D_3_OUTPUT_DEC -2
#define MAX_POOLING2D_3_OUTPUT_OFFSET 0
#define CONV2D_5_OUTPUT_DEC 1
#define CONV2D_5_OUTPUT_OFFSET 0
#define RE_LU_5_OUTPUT_DEC 1
#define RE_LU_5_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 3
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_3_input_config = {
    .super = {.name = "conv2d_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_3_kernel_0_data[] = TENSOR_CONV2D_3_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_3_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_dec[] = TENSOR_CONV2D_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_kernel_0 = {
    .p_data = (void*)tensor_conv2d_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_3_bias_0_data[] = TENSOR_CONV2D_3_BIAS_0;

const nnom_shape_data_t tensor_conv2d_3_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_3_bias_0_dec[] = TENSOR_CONV2D_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_bias_0 = {
    .p_data = (void*)tensor_conv2d_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_3_output_shift[] = CONV2D_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_3_bias_shift[] = CONV2D_3_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_3_config = {
    .super = {.name = "conv2d_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_3_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_3_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_2_config = {
    .super = {.name = "max_pooling2d_2"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_4_kernel_0_data[] = TENSOR_CONV2D_4_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_4_kernel_0_dim[] = {4, 2, 16, 12};
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

const nnom_shape_data_t tensor_conv2d_4_bias_0_dim[] = {12};
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
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_3_config = {
    .super = {.name = "max_pooling2d_3"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_5_kernel_0_data[] = TENSOR_CONV2D_5_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_5_kernel_0_dim[] = {2, 1, 12, 12};
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

const nnom_shape_data_t tensor_conv2d_5_bias_0_dim[] = {12};
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
    .filter_size = 12,
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
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {12, 6};
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
	nnom_layer_t* layer[13];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_3_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_3_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_2_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_4_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_3_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_5_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_1_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_1_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_1_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_55_NNOM_H