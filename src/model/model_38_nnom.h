#ifndef MODEL_38_NNOM_H
#define MODEL_38_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_38_nnom
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
#define TENSOR_CONV2D_4_KERNEL_0 {-24, 49, 22, -80, -5, 14, -31, 47, 8, -41, 26, -36, -48, 4, -8, 24, 13, -20, 48, -33, 47, -5, -94, -9, 23, -71, -34, 3, -23, 4, -49, -25, -40, -27, -89, 26, -92, 15, -68, -9, 10, -10, 17, -6, 50, -2, 63, 2, -19, -22, -28, 24, 3, 49, -5, 42, -34, -47, -30, -54, 70, -18, 37, -34, -19, -2, -46, 23, -45, 43, -3, -49, -52, -38, -79, -68, -36, -45, -2, -6, 28, 24, -14, -18, 15, -16, 32, -12, 35, 33, 50, -1, 46, 7, 14, -87, 7, 8, -19, -51, 5, -26, 18, 19, 7, 67, -12, 25, -50, 1, 54, -34, 66, -20, 31, 7, 22, 17, 52, -26, -18, -15, 25, -4, -38, 11, -57, -41, 5, -14, 75, 63, -23, -81, 46, 56, 25, 21, -21, -45, -4, 43, 0, -42}

#define TENSOR_CONV2D_4_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_4_BIAS_0 {-32, -47, 5, -72, 2, -10, 4, -1, 2, -13, -44, -34}

#define TENSOR_CONV2D_4_BIAS_0_DEC_BITS {8}

#define CONV2D_4_BIAS_LSHIFT {7}

#define CONV2D_4_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_5_KERNEL_0 {28, -9, 25, 89, 42, 19, 13, -4, -29, -14, -27, 33, 7, 37, 21, 18, -1, 16, 19, 12, 0, 20, -5, 48, -12, 11, -29, 72, 17, -32, -9, -14, -31, -76, -17, 34, -4, -4, 23, -52, -28, 29, 9, -3, -3, -5, 7, 42, -3, 37, -10, 1, -5, 9, -8, -1, -7, -53, 9, 29, 1, -8, 9, -38, -10, 37, -11, -9, -72, 8, 17, 21, -33, -19, 36, -28, -36, 18, -25, -22, -27, 20, 24, -16, 22, -57, -51, 61, -11, 12, -7, -2, -52, -7, 87, -10, 47, -22, -9, -9, -17, 39, -12, 20, -6, 34, -18, 23, -7, -23, 36, 33, 21, 22, 9, 11, -18, 21, 8, 33, 31, -9, 2, -21, -14, -4, -4, 3, -2, 8, 37, -4, 36, -26, -27, 30, -4, 5, 5, 1, -5, 2, 40, 8, 57, 46, 16, 7, -20, -11, 3, -5, -10, -2, 1, 29, 6, -10, -8, -68, 10, -11, 19, 20, 28, 40, 40, 15, 37, 43, 52, -1, 22, 33, -1, 11, -13, -12, -3, 82, 16, 77, 30, 5, 20, -21, -7, 44, -4, -49, 36, -7, -27, -22, -48, -8, -24, 61, 4, -22, -8, 15, -20, 19, -39, -3, -20, -7, -24, 53, 10, -7, 18, -21, -72, 4, -19, -31, -40, -2, -36, 49, 44, -39, 10, 2, 24, 16, -14, -18, -12, 1, -5, 65, -14, 39, -25, -62, 3, 0, -61, -36, 2, 22, 11, 11, -2, 18, 3, -13, 9, -13, -23, 9, -14, -53, -22, -14, 27, 3, 20, -31, 36, 69, 32, 88, -23, 55, 23, 29, -3, 11, 17, -8, -31, 9, -4, -8, 3, -1, 42, 36, -6, 51, 5, -13, -11, 50, 26, 24, 23, -49, 3, -9, 77, 40, 32, -11, 34, -9, 18, -20, 12, -105, -7, -16, 32, 1, 13, 2, -36, -2, 3, -2, 7, 57, 10, -8, 9, -9, -2, 3, 40, -10, -27, 43, -15, -99, 13, 28, 0, -1, 16, -5, 7, 27, 33, -11, -12, 20, 3, -42, 16, -5, 8, -3, 13, 18, -33, -22, 36, 28, 15, 51, 5, 53, -19, 53, -20, -5, -38, -36, 34, 79, -21, 2, -5, -9, -7, 30, -14, 8, -38, -14, -29, 38, 19, -25, -30, 42, -8, 17, -3, -7, 59, -61, -19, 71, -9, 25, -8, -2, -10, 14, 19, 54, 22, 22, 1, -5, -23, -10, -31, -35, -25, -2, 26, 50, 59, 22, -1, 99, 6, 15, 29, 0, 13, -1, -78, 3, 43, 29, -4, -24, 20, -58, 7, -14, 35, -34, -7, 81, -3, 24, 27, -36, 7, -35, -1, -2, -12, -43, 49, 18, 39, 39, -30, -43, 8, -30, -8, -18, -7, -7, 27, 47, 61, -6, 23, -28, -52, 55, -26, -34, -46, 77, 23, 22, 33, -22, 21, -19, -23, 17, -49, -13, 4, -1, 36, 17, 7, -6, 13, 19, 15, 34, -48, -2, -35, 5, 3, 1, -4, -84, 26, -47, 19, -10, 73, 1, 45, 11, -55, 15, -24, -2, -1, -62, -3, 32, -6, -38, -48, 20, -6, 17, -13, 56, 2, 55, 12, -34, 13, 11, 28, 16, -1, 10, -10, -52, -21, -2, 15, -12, 21, -25, 6, -5, -51, 26, 8, 34, 43, 90, 25, -37, -113, 6, 17, -48, 16, 18, -20, 23, -26, 33, -64, 34, -10, -11, 11, 2, -36, -42, 17, -11, -63, -91, -18, -28, -49, -74, -36, -68, 44, -12, 21, 10, -1, 64, 2, 53, 27, 34, 21, -15, -13, 32, -36, 4, 3, 31, -9, 33, 29, -25, 29, -1, -120, -90, 25, -14, 12, 70, 21, -71, -65, 16, -11, -10, -27, 41, -49, 18, -32, -86, 8, -60, -15, 14, 12, 5, -2, -24, 44, -49, 15, -44, 1, -39, -59, 25, -5, -81, 25, 19, -25, -55, 18, -31, 30, -11, -9, 1, -38, 23, 0, -28, 2, -11, 31, -63, -9, 19, 10, 37, -5, 38, -39, 18, -24, -20, 23, -76, 43, 9, 8, 23, 27, 45, -32, 8, 4, 52, 65, 22, 16, -23, 4, 28, 10, -5, -11, 3, 22, 51, -31, 33, -13, -108, 17, -32, 24, 25, -28, 10, -8, 59, 3, 30, 9, -12, 20, 11, -17, 41, 10, -32, -41, 25, 3, -17, -53, -21, 5, -18, -13, 15, -18, -8, -36, 43, -22, 46, 20, 4, 4, 1, 1, 14, 42, 2, -34, 43, -1, -127, -17, -15, -13, -13, -6, -12, -9, 37, 31, -23, -32, -66, 37, 37, -4, 23, -3, -1, 6, 30, 41, 2, 38, -53, 23, -18, 12, 5, 16, -15, -16, -50, -45, 17, -62, 80, 2, 40, 38, 15, 18, -6, 14, -32, -57, 81, -3, 53, -12, -8, -31, 29, -10, -33, -27, -5, 67, 2, -9, -13, -3, 21, -7, -8, 34, -11, -7, 0, -12, 0, 18, -4, 9, 26, 21, 10, -5, 33, -52, -21, -24, -26, 28, -17, 8, 27, -35, -18, 11, -42, 9, -4, 27, 36, 4, -29, 54, 28, 1, 19, -11, -44, -65, -44, 7, 0, 35, -75, -82, 28, -44, -100, -35, 61, -11, -37, 23, 2, -25, 3, -35, 8, 26, -67, 8, 7, -72, -3, 2, 48, -16, -34, -111, -7, -18, -2, 9, -38, 1, -85, -20, -33, -5, -117, 43, 34, -32, 22, -38, -80, -48, -28, -11, -29, 15, -92, -14, -25, 52, 2, 18, -10, -28, 3, 60, 0, -10, -62, 43, -6, 20, 3, 15, 0, 6, 33, 57, 17, -13, -52, 45, 45, 1, 1, -16, -32, -42, -9, 40, 36, 13, -36, 17, 9, 19, 6, 12, 38, 13, 9, -35, 3, 3, -84, 0, -10, -2, 12, -4, 27, -17, 40, 29, 11, 6, -77, 25, -21, 7, 38, 13, -19, 13, 13, 3, -79, -4, -62, 1, 12, 42, -22, 1, -30, -49, -47, -20, -18, -62, -14, 4, 34, 12, -1, 17, -34, -46, -41, -66, 9, 4, -16, 3, 20, 2, 2, -1, -24, -50, -14, 11, -7, -4, -35, -53, 22, -9, 25, 34, 30, -17, 25, -78, -70, -27, -32, -7, -15, -3, 19, -11, 14, 11, -36, 19, -76, -28, -51, -28, 14, 40, 7, 20, 5, -18, 16, -28, -70, -6, 77, 9, 23, 11, -8, 3, 9, -13, -46, -4, -48, -8, -53, 31, 7, 35, -24, 29, 23, -14, 53, 27, 26, 22, 64, 9, -24, 28, 11, -7, 36, -13, -8, -38, 10, 5, 12, -4, 1, -7, 60, 12, -2, 35, 1, 16, 60, 33, -3, 14, -3, 2, -7, -42, 14, 30, 30, 28, 46, 5, -9, 60, 34, 13, 65, 43, 51, 16, 32, -35, 13, 19, 49, 11, 0, 11, 10, 1, 24, 4, 20, -25, 14, 24, 18, 33, 21, 26, -13, 24, 5, 1, -17, -8, 17, 36, 47, -4, -4, 5, -13, -16, -15, -33, -8, 30, -9, 7, 53, 17, 24, 15, -1, -13, 17, 32, 20}

#define TENSOR_CONV2D_5_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_5_BIAS_0 {-99, -10, -6, -11, -57, 20, 4, -54, 14, 25, 48, -48}

#define TENSOR_CONV2D_5_BIAS_0_DEC_BITS {7}

#define CONV2D_5_BIAS_LSHIFT {6}

#define CONV2D_5_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_6_KERNEL_0 {16, 3, 24, -5, -17, -19, -15, 14, 13, 14, -8, 6, 9, 3, 8, 27, 15, -8, 24, 8, -6, 12, 3, 10, -25, 5, 19, 20, -39, -10, -14, -13, -5, 43, -13, -5, -38, 5, 7, -1, -17, 42, -8, 1, -10, -3, 29, 7, 11, -12, -11, 3, 15, 23, 23, -58, -4, -31, 27, 2, -7, -24, -18, 1, 0, -8, 1, -2, 15, 10, 2, 5, -1, -8, 22, -30, -11, 26, -30, -22, -18, -2, 10, -65, -18, 22, 5, -5, -43, 14, -55, -56, -58, 11, -9, -18, -29, 18, 20, -14, -34, 63, -23, -11, -25, 0, -1, -6, -33, 13, 1, 11, 10, -30, -8, -1, -1, 10, -2, -14, -58, 16, 2, 13, 22, 20, 0, -4, -13, -16, 5, -2, -21, 14, 22, -8, -24, -18, -3, 20, -43, -4, 28, -2, 7, 0, -9, -7, -5, 3, -2, -7, -9, -8, -2, -7, -2, -13, -9, -9, 6, -3, 3, -5, 5, -13, 4, -14, -2, 9, 0, -6, 22, 5, 4, 14, 4, -7, -7, -6, 35, 10, 13, 3, 35, -1, 8, 15, -2, -6, -19, 11, 13, -3, 13, -5, -9, -20, -9, 6, 19, -39, -7, 1, 12, -8, -5, -3, -7, -36, -8, -59, 20, 22, -30, -12, -9, 4, 9, 16, 18, 8, 26, -8, -14, -1, 0, -2, 28, 3, 3, -24, -9, -30, -1, 30, 13, -5, -3, 14, 7, 10, -6, 16, -32, 5, 1, -4, 1, -7, -5, 12, -29, -4, -1, 6, 8, 16, -5, -4, -22, 2, -14, 1, -8, -3, 13, 7, -8, 11, -1, -1, 18, 3, 8, 15, -31, -16, -16, 11, -28, -2, 5, -7, 0, 4, 17, 13}

#define TENSOR_CONV2D_6_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_6_BIAS_0 {-74, 30, 58, 17, 33, 9, -38, -48, 60, -68, -120, -11}

#define TENSOR_CONV2D_6_BIAS_0_DEC_BITS {8}

#define CONV2D_6_BIAS_LSHIFT {2}

#define CONV2D_6_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_7_KERNEL_0 {-37, 8, -12, 13, -41, 13, 6, -13, -20, 3, -16, -10, 2, -14, 8, 27, 4, -16, 3, 4, 13, -8, 6, -1, -30, 7, -25, 9, -31, 10, -3, -4, 5, 2, -9, -15, 3, -18, 5, 23, 6, -15, -2, 0, 4, -19, -1, -7, -8, -38, 19, -26, -21, -14, 3, 2, 2, 11, 6, 1, -22, 15, 2, -20, -53, -37, -3, -7, -34, 5, -1, 8, -4, 6, 2, -6, -5, 5, -9, -6, 8, 5, 7, 16, 7, -13, -19, -16, 4, -26, -1, 8, -4, 9, -1, -31, 5, -4, -22, -14, -39, -5, 11, 1, 23, 1, 14, 0, -13, 10, 5, 31, -9, 10, 0, 1, 25, 10, -19, -30, 1, -31, 14, 34, 5, -4, -4, 3, 22, 10, -18, -12, -14, 9, 36, -18, -16, -47, 10, -8, -11, 14, 2, -4, 17, 11, -28, 8, 24, -18, 7, -42, 4, -29, -15, 8, -30, -6, 8, -6, 4, -35, -2, -43, -4, -45, 22, -9, -12, 2, -4, 21, -3, 11, 6, -20, -15, -68, 8, -14, 1, 9, 5, 26, 7, 15, -11, -13, -16, -10, 14, -12, 8, -43, -23, -35, 8, -22, -7, 2, 6, 3, 21, -17, -3, 0, -8, -8, -6, 7, -10, 5, 6, -15, 7, -2, -9, -15, -2, -1, -21, 10, 0, 8, 18, 6, 12, 2, 2, -13, 6, -10, 16, -45, -8, 5, -6, -1, -3, -2, -20, -13, -11, 36, -4, 8, -9, -14, -29, -26, 29, -1, -1, 19, -5, 23, 4, 17, 3, -24, -19, -23, 12, -12, 16, 11, -12, 1, 26, -28, -7, -41, -25, -22, -6, 13, -24, -27, 9, -18, 11, -38, 0, -83, -6, -22, -2, 11}

#define TENSOR_CONV2D_7_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_7_BIAS_0 {31, 37, 27, -89, -34, -22, -10, -44, 28, -24, -32, -5}

#define TENSOR_CONV2D_7_BIAS_0_DEC_BITS {7}

#define CONV2D_7_BIAS_LSHIFT {1}

#define CONV2D_7_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_1_KERNEL_0 {-3, -23, -17, 5, 0, -11, 6, 9, 5, -20, 5, 5, 5, -15, -15, -29, 5, 1, -22, -21, 0, -22, 3, 3, 1, 9, -16, 0, 6, 6, 4, 3, 0, -5, -22, -6, -20, -44, 0, -1, 8, 4, -16, -15, -8, -32, 4, 3, -68, -53, -39, -30, -31, -34, -50, -36, -34, -23, -37, -43, -15, -18, -10, -15, -29, -16, 7, 4, -30, -24, 0, 4}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_1_BIAS_0 {-19, -2, -50, -8, 83, 5}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {5}

#define DENSE_1_BIAS_LSHIFT {1}

#define DENSE_1_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_4_INPUT_OUTPUT_DEC 9
#define CONV2D_4_INPUT_OUTPUT_OFFSET 0
#define CONV2D_4_OUTPUT_DEC 7
#define CONV2D_4_OUTPUT_OFFSET 0
#define RE_LU_4_OUTPUT_DEC 7
#define RE_LU_4_OUTPUT_OFFSET 0
#define CONV2D_5_OUTPUT_DEC 5
#define CONV2D_5_OUTPUT_OFFSET 0
#define RE_LU_5_OUTPUT_DEC 5
#define RE_LU_5_OUTPUT_OFFSET 0
#define CONV2D_6_OUTPUT_DEC 3
#define CONV2D_6_OUTPUT_OFFSET 0
#define RE_LU_6_OUTPUT_DEC 3
#define RE_LU_6_OUTPUT_OFFSET 0
#define CONV2D_7_OUTPUT_DEC 2
#define CONV2D_7_OUTPUT_OFFSET 0
#define RE_LU_7_OUTPUT_DEC 2
#define RE_LU_7_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_OFFSET 0
#define FLATTEN_1_OUTPUT_DEC 2
#define FLATTEN_1_OUTPUT_OFFSET 0
#define DROPOUT_1_OUTPUT_DEC 2
#define DROPOUT_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 1
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_4_input_config = {
    .super = {.name = "conv2d_4_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_4_kernel_0_data[] = TENSOR_CONV2D_4_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_4_kernel_0_dim[] = {6, 2, 1, 12};
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
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_5_kernel_0_data[] = TENSOR_CONV2D_5_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_5_kernel_0_dim[] = {4, 2, 12, 12};
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
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_6_kernel_0_data[] = TENSOR_CONV2D_6_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_6_kernel_0_dim[] = {2, 1, 12, 12};
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

const nnom_shape_data_t tensor_conv2d_7_kernel_0_dim[] = {2, 1, 12, 12};
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

const nnom_shape_data_t tensor_conv2d_7_bias_0_dim[] = {12};
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

const nnom_flatten_config_t flatten_1_config = {
    .super = {.name = "flatten_1"}
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

#endif //MODEL_38_NNOM_H