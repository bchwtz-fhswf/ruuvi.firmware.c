#ifndef MODEL_54_NNOM_H
#define MODEL_54_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_54_nnom
#define APP_ACTIVITY_RECOGNITION_PRECISION_FLOAT (0)
#define APP_ACTIVITY_RECOGNITION_SENSOR_SCALE (2)
#define APP_ACTIVITY_RECOGNITION_SENSOR_RESOLUTION (8)
#define APP_ACTIVITY_RECOGNITION_SAMPLING_FREQUENCY (100)
#define APP_ACTIVITY_RECOGNITION_FREQUENCY_DIVIDER (0)
#define APP_ACTIVITY_RECOGNITION_HIGHPASS_STAGES (2)
#define APP_ACTIVITY_RECOGNITION_INPUT_SIZE (1536)
#define APP_ACTIVITY_RECOGNITION_STEP_SIZE (256)
#define APP_ACTIVITY_RECOGNITION_CLASS_COUNT (6)
#define APP_ACTIVITY_RECOGNITION_FFT (1)
#define APP_ACTIVITY_RECOGNITION_FFT_SIZE (512)

#ifdef INCLUDE_MODEL
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_63_KERNEL_0 {-47, -7, -75, -9, 14, 8, 6, 3, 3, 2, 9, 4, -14, -41, -3, -4, -1, 3, -3, 69, -2, -8, -24, -24, 4, 8, 3, -3, 8, -6, 65, 3, 119, -14, -14, -5, -31, -4, 29, -4, -9, -6, 26, -4, -16, -1, -40, 40, -10, -83, -6, 5, -6, -8, -7, -16, -14, -5, -2, -4, 59, -1, 30, 24, 9, -29, 7, -34, -7, -1, 2, -26, -2, -7, -22, -7, -42, 1, -53, 3, -88, -11, 2, 2, 24, 28, 4, 64, -5, 21, -7, 6, 30, 1, -45, 7, 2, 8, 0, 11, 3, 13, 7, 3, 6, 46, 9, -98, 12, -4, -57, -9, 30, -19, -41, -4, -8, -6, 43, -6, 24, -13, 4, -85, -5, -13, 22, 6, 25, 4, 35, 2, 15, -22, 7, 41, 5, 10, 18, -48, 16, -1, 30, 20, -18, 50, -9, -17, 0, 1, 2, -24, 26, -17, 44, -19, -7, 2, 96, -6, -3, 3, -4, 9, -19, 0, 27, -8, 6, -6, -34, -4, 20, 7, 8, -3, -15, -14, -9, -28, -12, 13, -3, 16, 16, 8, -2, -11, 2, -20, 22, 42}

#define TENSOR_CONV2D_63_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_63_BIAS_0 {-71, -62, -76, -15, -30, -48, -38, -97, -38, -27, -83, -9, 27, 3, 36, 3}

#define TENSOR_CONV2D_63_BIAS_0_DEC_BITS {6}

#define CONV2D_63_BIAS_LSHIFT {3}

#define CONV2D_63_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_64_KERNEL_0 {-26, 8, -45, -41, -41, -37, 17, 2, 9, -2, 0, -44, 6, -32, -15, -19, 12, 14, -5, -10, -19, -25, -25, 15, -5, -28, -12, 6, -24, -27, -18, 11, -20, -15, -1, -4, -9, -49, 4, -7, -3, -31, -32, 9, 7, -5, 18, -30, 1, -2, 15, 3, -17, -14, -32, 18, -16, 9, -31, 8, 20, -11, -13, 21, 17, 24, 0, -1, -6, 4, 0, 37, 5, -41, -23, -26, -9, -24, 4, -17, 26, -31, 10, 16, -17, -11, -4, 6, -45, 14, 13, 34, -19, -30, -20, -2, -32, -13, -38, -36, -16, -34, 3, -43, -47, -4, -8, -26, -10, -14, -5, -36, 9, 16, 1, -59, -49, -65, -20, 4, 27, -51, -13, -42, -28, -10, 10, -21, 42, -11, -51, 0, -16, -40, 9, -4, -24, -4, -30, -10, -43, -63, -44, 22, -15, -24, 31, -50, -9, -3, -7, 18, -21, -25, -10, 8, -6, 18, -11, -26, -16, 20, -8, -47, 3, -34, 27, -9, 6, -30, -12, 12, -35, -42, -13, 20, -2, -32, 2, -6, -2, 2, -6, -10, 1, -3, -3, -26, -23, 19, 13, -6, -15, -50, -59, -19, 31, -24, 14, 11, -50, -15, -49, 1, -1, -45, -89, -4, -12, -5, -16, -69, -30, -21, -25, 25, -22, -49, -6, -24, -43, 8, -49, -6, 26, 29, -35, -5, 15, -21, 38, -18, 13, 4, -7, -19, -6, -74, 0, -20, 10, 13, -18, 9, -4, -31, 7, 17, -21, 18, -4, 4, -20, 21, 0, -21, 12, -17, 30, -1, 14, -7, 19, 8, -5, 1, 9, -24, -10, 16, -1, -19, 11, -5, -2, -12, -6, 8, -20, 4, 0, 7, 4, 10, -5, 14, -14, -11, 24, 1, 36, 13, -16, 15, 24, -12, 12, -15, 5, -8, -11, -6, -9, -1, -2, 4, 16, -22, 13, 4, 15, 17, 4, -5, 7, -18, 3, 2, -15, -7, 13, -4, 27, 2, -6, 0, 28, 22, 6, 6, -5, -3, 15, -4, -14, -3, 18, 6, 27, -2, 16, -7, 16, 16, 22, -3, 9, 1, -17, -12, 3, 0, 2, 19, 14, 2, 19, 9, 20, 22, 8, 8, 27, 14, -1, -7, -7, 1, 16, 29, 7, 6, 11, 11, 1, 25, 8, 16, 14, 10, -6, -7, -10, 13, -1, 2, -6, -6, -19, -6, -13, -15, -11, -14, 21, 22, 12, 3, 5, -9, 7, -14, 9, -13, -21, -24, 21, -23, -41, -13, -10, 8, -2, 12, 5, -25, 15, 3, -56, -37, -25, -20, -32, -35, -17, -27, 13, 13, 0, 1, 5, -12, 34, -36, -57, -21, -8, -9, -45, -24, -63, -5, -30, -15, -8, 7, -8, -30, -9, -12, 2, 16, 2, -25, -8, 26, 41, -18, 21, 16, -31, -13, -5, 20, 20, -2, 24, -44, -12, -23, -12, -3, -3, 30, 19, 5, 15, 5, -7, 7, 6, 19, 14, -29, -93, -44, -8, 13, -16, -4, -10, -28, -9, -18, -19, -36, 20, 12, 33, 4, -72, -1, -17, -15, -33, 15, 16, 5, 5, -19, 4, -26, 29, -36, -21, 4, -24, 22, 10, 26, 14, 21, 47, 9, -25, 4, 15, 0, 18, -54, -20, -6, -17, -1, 18, 12, 15, 17, 4, -37, -24, 30, 3, 9, -7, 1, 42, -13, 2, -8, 6, 18, -16, -56, -8, -16, 4, -47, -39, 17, -4, 31, 22, -4, 27, 25, 10, 12, 12, -17, -21, -21, -24, -55, -17, -5, 7, -47, -7, -28, -22, -19, -13, -61, -11, -39, -20, -28, -42, -18, -19, -35, -21, -15, -19, -23, -42, -15, 0, -29, -18, -23, -8, -41, -29, -15, -13, -38, 16, 4, 21, 3, -11, 7, 23, 32, 11, 14, 17, -9, -11, 17, 12, 4, 9, -6, 21, 22, 23, 6, 22, 11, 29, -1, 4, 15, 19, -1, 0, 19, 13, 2, 6, 4, 19, 8, 5, 21, 6, 4, 19, 4, 17, 17, 17, 12, 7, 3, 14, -1, 19, 5, 22, 30, 2, 10, 25, 10, 28, 14, -8, 7, -11, -2, 14, -3, -31, -9, 7, -12, 25, -4, -11, 11, 0, -17, -14, 0, -20, -6, 11, 7, -11, -29, 10, -15, 24, 1, -28, -17, -19, -14, -4, 16, -3, 11, -6, -11, 4, -13, -1, 11, -6, -9, 3, 20, 8, -6, -5, -7, 7, -3, 6, 11, 3, -5, 7, -15, 15, 2, 0, -14, -9, 1, -4, 7, -11, -20, 4, 16, -16, -25, -1, -9, 7, 9, -16, -4, -10, 12, 10, 4, -7, -3, -8, 1, -5, -27, -17, -20, 0, 3, -23, -9, -1, 10, -17, -1, -68, -23, 29, -40, -27, 50, 2, 7, -15, -51, 17, -28, 4, 16, 8, -9, -43, 31, -5, -8, 0, -63, -7, -34, 4, -32, -9, 2, 0, -22, 26, 0, -87, -59, -86, -57, -63, -113, -21, -42, -61, -66, -78, -17, -3, -19, 1, 4, 11, 4, -5, -26, -5, -16, 6, 19, 4, -29, -1, 7, 7, -1, -3, -5, -62, -12, -42, -29, 9, -32, -12, -22, -38, -11, -39, -46, 5, -8, 12, -4, -7, 15, -55, 4, 11, -8, -4, 37, -38, -23, 53, -19, 1, 20, 25, 19, -42, -79, -59, -62, -48, -74, -3, -36, -32, -80, -63, -34, 21, -24, 18, 14, -34, -2, -41, -20, -14, -43, 18, -11, -28, -42, 8, -3, 31, 20, 10, 7, 5, 1, -15, -41, -12, -18, 30, 12, -4, -22, 23, -10, -25, 13, -52, -21, -9, -28, 12, -4, 7, -26, 27, -41, 7, -25, -4, 11, -29, -5, -29, -5, 33, -18, -7, 32, 9, -40, 11, -3, 19, 27, -6, -6, 13, -7, 20, 6, 13, -6, 12, -15, 0, -14, -23, -19, -1, -14, 3, 6, -30, 18, -16, 1, -25, -11, 37, -15, -32, -15, -24, -19, 5, -26, -21, 10, -37, -31, 7, -21, -29, -3, 19, 9, 5, -20, -16, 6, 13, 29, -22, -20, -7, -15, -21, -6, 6, 19, -9, -31, -18, -12, -29, -29, -15, -7, 4, 13, -41, 22, -36, -41, -20, -19, -23, -15, -17, -8, -26, -1, -32, 0, -8, -23, -15, 0, -13, -31, 11, -10, -42, -7, -7, -7, 3, -58, -35, -20, -14, -8, 7, 1, -13, -35, 15, -12, 8, -1, 3, -16, 18, 13, -66, -16, 28, -1, -54, -35, -85, 10, -16, 13, 8, -13, 4, -8, 3, -15, -16, -23, 11, -8, 46, 14, 7, -1, 12, 10, -16, 11, 21, -38, 2, 11, 15, -14, 27, -10, 14, 1, -75, 4, -12, 2, -1, -29, -30, 2, 27, -46, -21, -56, 12, 5, -3, -13, -30, -28, -12, 21, -3, -15, -42, -94, 11, 24, -4, -72, -35, 21, -34, -20, -21, 10, -6, -8, 12, -11, -6, -3, 9, -11, -6, 1, -24, 1, 11, 0, 2, 5, -26, -10, 5, -19, -107, -9, -17, 37, 19, 3, -55, 7, 7, -4, 9, 28, -3, -8, -5, 10, -11, 12, 35, -18, -3, -15, 6, -4, 24, 17, 22, 1, -14, -27, 7, -23, 4, 7, -9, -19, -25, -31, -19, -15, 5, 25, 25, -1, -22, -34, -64, -15, -4, -15, 21, -8, -48, 8, -61, 0, 4, -4, 25, 32, -59, -21, -17, -31, 3, -7, 9, -16, -27, 2, -19, -8, 17, 26, -4, 12, -34, 11, -62, -43, -5, -25, 1, -42, -13, -41, -19, -17, -11, -19, 38, -11, 1, 12, 1, 14, 9, 8, 4, 28, -27, -19, -22, -6, 32, 16, 13, 8, -117, -89, -93, -60, 7, -22, 3, -64, -60, -9, -55, -20, 17, 11, 27, 8, -11, -13, -75, -25, 2, -17, 21, -23, -36, -37, -44, -26, 12, -4, 16, -21, -34, 20, -37, -7, 2, -24, -17, -19, 12, 0, -2, 36, -12, 0, 2, -10, -5, 22, -7, -19, 4, 21, 25, 19, -3, 3, -39, 23, 32, 6, 0, 13, -37, -24, -18, -8, -8, -12, 5, -19, -15, -25, -4, 1, 14, -20, -3, -11, 4, 1, 2, -3, 20, -4, -17, -15, -31, -10, 3, 1, 33, -3, -1, -7, -41, -8, -56, -31, 8, 3, -40, -33, -68, -15, -8, -24, -15, 7, -2, -5, 30, -37, -47, 6, -28, -27, -57, -26, -80, -41, -40, -41, -28, -24, -36, -27, -20, -7, 1, 5, 6, 16, 8, -18, 4, -6, 9, 2, 8, 46, -8, 17, -28, -25, 1, 36, -11, -37, 8, 23, 0, 23, 24, 26, 1, -29, -30, 25, -37, -11, -27, -10, 18, -13, -36, -35, -52, -13, 16, -42, 14, -32, -6, -5, -13, -17, -61, -13, 5, -14, -23, -35, -22, -39, -39, -10, 7, 10, -22, -35, -14, 16, -14, 27, -22, 23, -25, 22, 12, 29, 0, 0, -27, 21, 26, 10, -7, 16, -27, 1, 19, -3, -20, 6, 22, -2, -8, 18, 24, 8, -2, 26, -16, 13, -8, 3, -23, -19, -2, 0, -6, 24, 9, 18, -4, -24, -3, -4, -23, 26, -13, 15, 3, 12, -4, 4, -3, -9, -8, 6, -14, -21, -28, -10, 18, -4, 7, 10, 13, 16, 12, 21, 24, 18, 5, 3, -5, 29, 27, 5, 15, -2, 21, 13, -1, -8, 12, 8, -11, 8, 8, 1, 2, 9, 9, 4}

#define TENSOR_CONV2D_64_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_64_BIAS_0 {4, -42, -71, 30, 27, -1, 35, -3, 9, 47, 1, -17}

#define TENSOR_CONV2D_64_BIAS_0_DEC_BITS {6}

#define CONV2D_64_BIAS_LSHIFT {3}

#define CONV2D_64_OUTPUT_RSHIFT {10}

#define TENSOR_CONV2D_65_KERNEL_0 {4, -18, -6, 0, -29, -27, 8, 24, 31, 10, -6, 3, 29, 32, -9, 2, -9, -29, 18, 1, -19, -2, -3, -2, 4, -18, -2, -12, -13, 21, 7, 1, -15, -16, -22, -11, 1, -1, 8, 7, -8, -33, 2, -17, -8, -5, 11, -5, 0, -4, -23, 14, -6, 3, 0, -24, -3, -11, -4, 24, -14, -14, -8, 2, -10, -12, -44, -28, 4, 20, -4, -24, 12, 0, 9, -4, -1, 4, -84, -16, -1, 28, 10, -6, 2, 17, 9, -13, -20, -1, 34, 1, 4, 18, -28, -14, 11, 15, -19, -4, 7, 19, 17, 3, 13, 9, 8, 10, -22, -6, -24, -25, 2, -28, -7, 16, -24, -15, -28, -6, 1, -9, -47, 10, 7, -19, -11, -11, -5, 6, 10, -15, 7, -8, -22, 11, 3, -15, 8, 9, -16, -1, -4, -22, 26, -13, 3, -36, -12, 17, -55, -1, -5, -3, 16, -14, 14, 9, -16, -9, 15, -14, -19, -1, -8, 25, 0, -15, 0, 12, 4, 4, 14, -4, 18, 11, -1, 25, 9, -5, -4, -16, -16, -14, -5, 6, 1, -19, 2, -18, -27, -20, -2, -9, -15, 25, -45, 9, 20, 9, 26, -11, -2, 7, 27, 16, -3, -23, -5, -8, -86, -35, 24, 39, -18, -11, 2, -20, -17, -19, -34, -17, -4, -9, 9, -16, -16, 9, -19, -27, 12, 3, 20, 2, -22, -30, -7, 22, 8, -13, -18, 1, -30, 11, 4, -13, 20, 18, -27, 17, -15, -36, 13, 5, -29, 8, 11, 4, 9, -11, 9, 21, -9, -6, 6, -7, 6, 15, 7, -16, -7, -8, -6, -14, 9, 1, 12, -11, -9, 2, -10, 10, -23, 25, 3, 10, -2, -7}

#define TENSOR_CONV2D_65_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_65_BIAS_0 {9, 12, -1, -47, -4, 4, 17, 57, 5, -27, 45, 36}

#define TENSOR_CONV2D_65_BIAS_0_DEC_BITS {6}

#define CONV2D_65_BIAS_LSHIFT {0}

#define CONV2D_65_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_21_KERNEL_0 {-38, -49, 47, 50, -28, -40, 18, 22, -76, -19, 67, 39, -29, -11, -14, -52, 4, 2, -8, 11, -48, 1, 19, 44, -78, 33, -46, -90, 9, 10, -35, -18, 62, 25, -80, 57, 26, 27, -90, -86, 18, -18, -47, -45, -30, -32, 6, -5, 36, -21, -50, -79, 73, 12, -6, -19, -64, -76, 107, -55, -27, -46, -1, -32, -22, 2, 72, -27, 32, -4, -73, 23}

#define TENSOR_DENSE_21_KERNEL_0_DEC_BITS {7}

#define TENSOR_DENSE_21_BIAS_0 {-46, -74, 40, 44, 26, 1}

#define TENSOR_DENSE_21_BIAS_0_DEC_BITS {7}

#define DENSE_21_BIAS_LSHIFT {1}

#define DENSE_21_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_63_INPUT_OUTPUT_DEC 0
#define CONV2D_63_INPUT_OUTPUT_OFFSET 0
#define CONV2D_63_OUTPUT_DEC 2
#define CONV2D_63_OUTPUT_OFFSET 0
#define RE_LU_63_OUTPUT_DEC 2
#define RE_LU_63_OUTPUT_OFFSET 0
#define MAX_POOLING2D_42_OUTPUT_DEC 2
#define MAX_POOLING2D_42_OUTPUT_OFFSET 0
#define CONV2D_64_OUTPUT_DEC -1
#define CONV2D_64_OUTPUT_OFFSET 0
#define RE_LU_64_OUTPUT_DEC -1
#define RE_LU_64_OUTPUT_OFFSET 0
#define MAX_POOLING2D_43_OUTPUT_DEC -1
#define MAX_POOLING2D_43_OUTPUT_OFFSET 0
#define CONV2D_65_OUTPUT_DEC 1
#define CONV2D_65_OUTPUT_OFFSET 0
#define RE_LU_65_OUTPUT_DEC 1
#define RE_LU_65_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_21_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_21_OUTPUT_OFFSET 0
#define DENSE_21_OUTPUT_DEC 2
#define DENSE_21_OUTPUT_OFFSET 0
#define SOFTMAX_21_OUTPUT_DEC 7
#define SOFTMAX_21_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_63_input_config = {
    .super = {.name = "conv2d_63_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_63_kernel_0_data[] = TENSOR_CONV2D_63_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_63_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_63_kernel_0_dec[] = TENSOR_CONV2D_63_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_63_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_63_kernel_0 = {
    .p_data = (void*)tensor_conv2d_63_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_63_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_63_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_63_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_63_bias_0_data[] = TENSOR_CONV2D_63_BIAS_0;

const nnom_shape_data_t tensor_conv2d_63_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_63_bias_0_dec[] = TENSOR_CONV2D_63_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_63_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_63_bias_0 = {
    .p_data = (void*)tensor_conv2d_63_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_63_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_63_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_63_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_63_output_shift[] = CONV2D_63_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_63_bias_shift[] = CONV2D_63_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_63_config = {
    .super = {.name = "conv2d_63"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_63_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_63_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_63_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_63_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_42_config = {
    .super = {.name = "max_pooling2d_42"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_64_kernel_0_data[] = TENSOR_CONV2D_64_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_64_kernel_0_dim[] = {4, 2, 16, 12};
const nnom_qformat_param_t tensor_conv2d_64_kernel_0_dec[] = TENSOR_CONV2D_64_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_64_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_64_kernel_0 = {
    .p_data = (void*)tensor_conv2d_64_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_64_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_64_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_64_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_64_bias_0_data[] = TENSOR_CONV2D_64_BIAS_0;

const nnom_shape_data_t tensor_conv2d_64_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_64_bias_0_dec[] = TENSOR_CONV2D_64_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_64_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_64_bias_0 = {
    .p_data = (void*)tensor_conv2d_64_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_64_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_64_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_64_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_64_output_shift[] = CONV2D_64_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_64_bias_shift[] = CONV2D_64_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_64_config = {
    .super = {.name = "conv2d_64"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_64_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_64_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_64_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_64_bias_shift, 
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_43_config = {
    .super = {.name = "max_pooling2d_43"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_65_kernel_0_data[] = TENSOR_CONV2D_65_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_65_kernel_0_dim[] = {2, 1, 12, 12};
const nnom_qformat_param_t tensor_conv2d_65_kernel_0_dec[] = TENSOR_CONV2D_65_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_65_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_65_kernel_0 = {
    .p_data = (void*)tensor_conv2d_65_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_65_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_65_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_65_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_65_bias_0_data[] = TENSOR_CONV2D_65_BIAS_0;

const nnom_shape_data_t tensor_conv2d_65_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_65_bias_0_dec[] = TENSOR_CONV2D_65_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_65_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_65_bias_0 = {
    .p_data = (void*)tensor_conv2d_65_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_65_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_65_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_65_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_65_output_shift[] = CONV2D_65_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_65_bias_shift[] = CONV2D_65_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_65_config = {
    .super = {.name = "conv2d_65"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_65_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_65_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_65_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_65_bias_shift, 
    .filter_size = 12,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_21_config = {
    .super = {.name = "global_max_pooling2d_21"},
    .output_shift = 0,
};
const int8_t tensor_dense_21_kernel_0_data[] = TENSOR_DENSE_21_KERNEL_0;

const nnom_shape_data_t tensor_dense_21_kernel_0_dim[] = {12, 6};
const nnom_qformat_param_t tensor_dense_21_kernel_0_dec[] = TENSOR_DENSE_21_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_21_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_21_kernel_0 = {
    .p_data = (void*)tensor_dense_21_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_21_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_21_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_21_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_21_bias_0_data[] = TENSOR_DENSE_21_BIAS_0;

const nnom_shape_data_t tensor_dense_21_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_21_bias_0_dec[] = TENSOR_DENSE_21_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_21_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_21_bias_0 = {
    .p_data = (void*)tensor_dense_21_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_21_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_21_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_21_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_21_output_shift[] = DENSE_21_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_21_bias_shift[] = DENSE_21_BIAS_LSHIFT;
const nnom_dense_config_t dense_21_config = {
    .super = {.name = "dense_21"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_21_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_21_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_21_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_21_bias_shift
};

const nnom_softmax_config_t softmax_21_config = {
    .super = {.name = "softmax_21"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_21_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_63_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_63_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_42_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_64_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_43_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_65_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_21_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_21_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_21_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_54_NNOM_H