#ifndef MODEL_49_NNOM_H
#define MODEL_49_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_49_nnom
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
#define TENSOR_CONV2D_4_KERNEL_0 {-60, -110, -26, 67, 46, -17, 29, -13, 24, 51, -11, 18, -40, 7, 30, -37, 24, -23, -27, -14, -35, -10, -25, -81, -61, 13, 43, 0, 37, 8, -52, -2, -56, 9, 39, -1, -82, 67, 14, 24, -36, -39, 0, 49, -3, -2, 15, -40, 9, -47, 26, -53, 7, 43, -23, 59, -7, -4, -3, 94, 43, 16, 35, -49, -28, -64, -24, 10, 35, 46, -62, -41, 42, 53, 45, -30, 27, 3, -46, -25, -83, -54, -73, -33, 33, -9, 22, -30, -20, -27, -53, -42, 3, 97, 60, -60, 73, -10, 79, -7, -28, -15, 14, -8, -56, -25, -81, 9, 4, -67, -3, 66, -28, 33, 6, 15, 14, -75, 9, -41, -32, -60, 14, 3, 57, 96, -27, 3, -42, -16, -33, -84, -86, 40, -81, 21, -58, 1, 10, -22, 96, 11, 83, -22}

#define TENSOR_CONV2D_4_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_4_BIAS_0 {-56, 6, -73, -38, -14, -72, 3, -15, -89, -13, -38, -52}

#define TENSOR_CONV2D_4_BIAS_0_DEC_BITS {8}

#define CONV2D_4_BIAS_LSHIFT {7}

#define CONV2D_4_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_5_KERNEL_0 {23, 15, 62, 47, -6, 23, 9, 13, -14, 6, -19, 20, -8, -9, 12, -29, -12, 9, -12, 0, -19, 23, 12, -44, -2, 8, -38, -19, 9, -37, -12, 13, -69, -3, 2, -40, 19, -18, 15, 62, -7, 8, -13, -15, -64, 15, 0, -10, 5, 8, -46, -3, 0, 9, -7, 13, 27, 8, 0, -12, -4, -5, -6, -24, -10, 1, 4, -4, -10, 25, 30, -54, 16, -1, 28, -1, 6, 18, -4, 27, -1, 9, 4, -66, 27, -5, 23, -36, 1, -20, 3, 33, -28, 19, 17, -21, 14, -24, 50, 8, 3, 7, 6, 11, 56, -4, 8, -20, 15, 3, 10, 26, -5, -12, 6, -8, 27, 13, 28, 7, 21, -14, 48, 10, 4, -15, -14, 25, 18, -14, -1, 9, -2, 12, 20, 24, 21, -11, -24, 9, 5, -14, 19, -48, 4, 1, -66, 14, 19, 12, -10, 27, 26, 13, -16, 5, -29, 21, 50, 15, 18, 6, 11, 3, 19, 13, 9, -27, 6, 19, 9, -6, 7, 0, 3, 26, -15, -1, -8, 4, 8, 7, 6, 18, 20, -7, 20, 3, -31, 15, -6, 32, 16, -29, -21, 10, 15, 15, 0, 14, 65, -5, -22, -4, 5, 5, -65, 17, 25, -5, -25, -7, -50, -17, -12, 32, 4, -21, -44, -3, -17, 21, -11, 5, 95, 25, 15, 15, -19, 17, 7, -1, 45, 4, 7, -31, -17, -11, -30, 7, 7, -14, -28, -15, -17, 7, 4, 3, 17, 10, -17, -24, -9, 11, 56, -37, 7, -33, 22, -4, 17, -17, -33, -4, 16, 4, -3, -10, -10, -18, 10, 10, -36, 19, -8, -25, -5, -1, 9, -23, 11, -77, 11, 1, 17, -34, -6, -34, -6, -26, 54, -7, 19, 11, -27, 18, 12, 19, 22, 39, 11, 2, 28, -8, -22, 5, -3, -25, 5, -44, 8, -22, -28, 11, -4, -23, 33, -9, -57, 23, 31, 5, -14, -40, 0, 9, 27, 20, -24, 25, -5, -17, 3, -44, -16, -30, -18, 5, -51, 23, 14, 16, -10, 32, 42, 21, 12, -61, 22, -4, -39, 33, -20, 3, 2, -44, -16, -2, 9, -11, -28, 18, 33, 3, -12, 22, 10, 2, -2, 3, -42, -7, -1, -16, -26, -12, -8, -5, -9, 20, 0, -7, -41, -33, -24, -14, -25, -1, -8, -17, -42, 1, 79, -13, -2, -9, 4, 10, 25, -5, -3, -25, -50, -4, -21, -19, -5, 4, -43, 17, -52, 1, 8, -5, 13, 5, 10, -11, -34, -2, -11, -7, -23, 5, 2, 1, -13, 14, -1, -16, 1, -26, -7, 32, 27, 0, -11, 13, 14, -13, -49, 11, 12, -9, -24, 2, -3, 2, 17, -6, 12, -17, 15, 31, 1, 15, 39, -38, -12, 6, 1, 31, -18, -3, 36, 2, -20, -10, -34, 15, 26, 3, 21, 1, 14, 23, -25, 10, -18, -38, -49, 9, -37, 25, 8, -14, 0, -15, -21, 11, 3, -47, -15, 6, -20, 9, 6, 0, 10, -13, 2, 17, 0, 5, 9, 10, -12, 8, 3, 6, -27, -15, -24, -32, 17, 27, -54, 2, -15, -18, 26, 8, 17, 31, 5, 16, 13, -13, -15, -16, -32, -11, -2, -28, -15, -4, -45, -14, -7, 19, -10, -2, -85, 4, -6, -3, -8, -3, 3, 32, 14, 5, 18, 14, -37, -8, -11, -25, 5, -13, 7, -15, -7, -3, 11, 9, -16, -5, 36, 10, -1, -43, -90, 14, 27, 3, 17, 9, 82, 51, 10, 16, 5, 25, -8, 40, 13, -29, 17, 31, 22, -16, -16, -8, -42, 4, 25, -7, 15, -16, 20, -50, 34, -13, 1, 8, -32, 32, -17, 2, -2, -28, 23, 8, 21, 37, 35, -14, 4, 6, 29, 3, 0, -17, 3, 30, -18, 5, 8, 4, -4, 12, -5, -19, 8, 13, -21, -18, 9, 18, -4, 21, -9, 26, 7, -8, -19, -47, -15, 0, 32, 10, 20, 28, -17, 4, -21, -14, 13, -16, -5, -18, 10, -12, 5, 20, -14, 4, 12, -1, 8, -3, 5, 5, 3, 31, 1, 14, 21, -16, 34, -24, -52, 32, -28, 12, 33, -40, 15, -31, 24, 20, 40, -6, -22, 5, -6, 19, 9, 4, 12, 4, 3, -7, -9, -23, -8, 21, -23, 2, -31, 3, 3, -16, 33, 5, -1, 14, -23, 40, 15, 10, -13, 33, 15, -33, -6, -38, 27, 12, 25, 11, 14, 6, -31, -9, 18, 10, 0, -19, 21, -3, -2, 15, -13, -18, 65, 1, -8, -13, 5, -21, 53, 8, 13, 10, -7, -2, -21, -1, 5, 16, -3, 11, 0, -20, 5, 13}

#define TENSOR_CONV2D_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_5_BIAS_0 {18, -91, -6, 27, 60, 60, -10, -17}

#define TENSOR_CONV2D_5_BIAS_0_DEC_BITS {7}

#define CONV2D_5_BIAS_LSHIFT {5}

#define CONV2D_5_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_6_KERNEL_0 {-3, -68, -76, -41, -34, 17, 24, -20, 39, -82, 0, -10, -5, 3, -45, -40, 7, 23, -17, 28, 17, -9, 28, -12, 19, -7, -11, 11, -3, -16, 29, -12, -16, -7, -4, -7, -14, -15, 5, -17, -13, -22, -3, 5, -14, -10, 0, -7, -2, 2, 9, -1, -15, 12, 33, 4, 4, -16, -12, 43, -42, 13, 25, 18, -3, 2, 28, 9, -31, -53, 16, 18, 2, 19, -10, 4, -8, -41, -3, 19, 26, 25, -5, 11, -1, 6, 1, 19, 3, 38, -27, -3, 22, -7, 4, 17, 27, 15, -4, 28, -42, -23, 11, 8, 4, 33, 2, -6, -10, -30, -6, 19, 2, 12, -32, 18, 8, -67, 11, 1, 11, -13, 21, 29, 4, -43, 1, -49}

#define TENSOR_CONV2D_6_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_6_BIAS_0 {21, -10, -16, 28, -83, 0, -58, -10}

#define TENSOR_CONV2D_6_BIAS_0_DEC_BITS {6}

#define CONV2D_6_BIAS_LSHIFT {4}

#define CONV2D_6_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_7_KERNEL_0 {-7, 2, -2, 3, -5, -1, 5, 8, -2, 5, -4, -16, 12, -2, 1, 10, 2, 4, -6, 1, 6, -3, 15, 17, 1, 5, -5, -32, 12, 2, 12, 0, 20, -16, -2, 4, -15, -5, -5, -15, 9, -79, 2, 6, -7, -17, -8, -20, -20, -27, 5, -4, -7, -1, 14, 0, -11, -2, -7, -1, -7, 2, -13, -6, 22, -11, 2, 4, -17, -14, -44, -13, 10, -14, -2, 6, -6, -22, -31, -19, -2, 8, -4, 3, 2, -2, 3, 16, 2, 8, 5, -30, 21, 0, -10, 26, -2, 10, -4, -1, 4, 5, -7, 4, -23, 3, 0, -14, 20, -13, -10, 13, -18, -30, -4, 5, -32, -1, -37, -13, -41, -6, 0, -16, 6, -8, 23, 12}

#define TENSOR_CONV2D_7_KERNEL_0_DEC_BITS {4}

#define TENSOR_CONV2D_7_BIAS_0 {-2, 3, -7, -3, -3, 3, 0, 4}

#define TENSOR_CONV2D_7_BIAS_0_DEC_BITS {4}

#define CONV2D_7_BIAS_LSHIFT {0}

#define CONV2D_7_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_1_KERNEL_0 {1, -4, -28, -23, -7, -34, 2, 0, 7, 6, -14, 5, 2, -1, -28, -45, -24, -20, 8, -9, 4, 2, 3, -12, 5, 1, -18, 6, 2, -4, 1, -3, -54, -49, -53, -83, -47, -49, -56, -124, -44, 1, 5, -36, 7, -4, -27, -52}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_1_BIAS_0 {-49, -15, -32, 6, 67, 2}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {5}

#define DENSE_1_BIAS_LSHIFT {0}

#define DENSE_1_OUTPUT_RSHIFT {6}


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
#define CONV2D_7_OUTPUT_DEC 1
#define CONV2D_7_OUTPUT_OFFSET 0
#define RE_LU_7_OUTPUT_DEC 1
#define RE_LU_7_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_OFFSET 0
#define FLATTEN_1_OUTPUT_DEC 1
#define FLATTEN_1_OUTPUT_OFFSET 0
#define DROPOUT_1_OUTPUT_DEC 1
#define DROPOUT_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC -1
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

const nnom_shape_data_t tensor_conv2d_5_kernel_0_dim[] = {4, 2, 12, 8};
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

const nnom_shape_data_t tensor_conv2d_5_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_6_kernel_0_data[] = TENSOR_CONV2D_6_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_6_kernel_0_dim[] = {2, 1, 8, 8};
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

const nnom_shape_data_t tensor_conv2d_6_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_7_kernel_0_data[] = TENSOR_CONV2D_7_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_7_kernel_0_dim[] = {2, 1, 8, 8};
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

#endif //MODEL_49_NNOM_H