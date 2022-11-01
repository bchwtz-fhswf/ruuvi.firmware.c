#ifndef MODEL_39_NNOM_H
#define MODEL_39_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_39_nnom
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
#define TENSOR_CONV2D_12_KERNEL_0 {36, -45, 29, -28, 25, 93, -20, -42, -12, 1, 2, -46, -86, 17, -59, -31, -4, -31, 31, 43, 18, 33, 85, 47, -109, 21, -2, 28, -51, -8, 8, -25, -43, -40, -52, -3, 37, 6, 86, -18, 54, -54, -6, 8, -42, 13, -39, 61, 56, 27, 27, -10, 0, 18, 44, 49, 71, -31, -62, -78, -89, 31, -35, -34, 60, -37, 5, 37, -55, 1, 27, -36, 60, 74, 10, 58, -43, -20, -44, -70, -5, -8, 40, 6, -24, -3, 20, 7, 12, -1, -17, 35, -26, 108, -58, 74}

#define TENSOR_CONV2D_12_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_12_BIAS_0 {29, -38, -5, -67, -21, -71, -22, 20}

#define TENSOR_CONV2D_12_BIAS_0_DEC_BITS {9}

#define CONV2D_12_BIAS_LSHIFT {6}

#define CONV2D_12_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_13_KERNEL_0 {-3, 35, -3, 26, 5, -10, -21, 29, 8, 24, 22, 5, 17, 4, 2, -15, 8, 11, 0, 2, 30, -22, -10, 3, 18, -11, 15, -30, 10, 23, -12, 27, -2, 5, 32, 15, -1, 10, 8, 4, 12, 3, 9, -15, 22, 0, 15, -1, -11, 12, 9, -14, 23, 39, -26, 0, 2, 8, 4, 4, 20, -4, 14, -20, 13, -47, -9, -55, 8, 22, -65, -10, -2, -25, 7, -62, 28, 13, -15, 6, -11, -30, 12, -22, -71, 42, -19, 2, -6, 9, -13, -16, 28, 15, -13, 7, 7, -26, -17, -27, 14, 27, 24, -4, -13, -9, -14, -92, 9, -10, -16, -4, 2, -30, -40, 7, 23, 22, -29, -16, 10, -2, -12, -32, 20, 21, -49, 2, 27, 0, -5, -8, -5, 12, 25, -12, -21, 9, 11, 3, -9, 27, -27, -4, -5, 3, -10, 16, 1, -9, 0, -32, 11, 2, 14, -1, -30, 13, 45, -33, 41, -16, -5, -49, -14, -3, 8, 20, -2, 9, 1, 9, -4, 5, -11, 15, -16, -26, 7, -11, -2, -34, 5, 12, 5, 5, 4, 16, 14, -21, -13, 31, 5, -10, 6, -12, 29, 31, 19, 30, -8, -24, -28, 15, 22, -28, 7, -27, 19, 1, -9, 25, 9, 4, 1, 5, -21, 3, -26, 5, 0, 0, -13, -9, -2, -9, 13, 4, 2, -9, 29, -3, -20, 17, -8, -11, 17, -6, 12, -45, 23, 19, 18, 35, 12, 24, 24, 9, -29, -3, 15, 1, 16, -7, 5, -5, -19, 5, 8, 9, 2, -11, -6, -25, 9, -21, -3, 5, 9, 26, 11, 7, 7, -3, 2, 2, -15, -12, -1, 8, -3, 17, 7, 3, 7, 22, -3, -3, 38, 26, -21, 10, -23, -21, -13, 1, -1, -3, 7, 14, 4, 0, -7, 8, 9, 37, -36, 24, -18, -19, 7, 5, -39, -2, -14, -27, -20, -8, 13, -20, -17, -3, 10, -6, -9, 19, 27, -22, 9, -37, -36, 0, -12, -38, -3, 4, -3, -4, 3, -2, 2, -12, 6, 0, 11, 2, 8, 1, -15, -9, 5, -11, 0, 13, -26, -10, 2, -16, 2, 11, 16, 8, -5, 22, -4, -23, 11, -6, 8, -30, 6, -3, -6, 1, 33, -20, 3, -21, 3, -4, 12, -3, 16, 14, 25, -7, 15, -29, -8, 32, 18, 27, -5, -6, 28, 2, -28, 33, 6, 7, 19, 0, 17, 12, 12, 3, -10, 20, 9, 19, -16, -23, 31, -26, -7, -14, -9, -25, -3, -7, 19, 21, 4, -25, -18, -4, -16, -7, 3, -18, -23, -10, -3, -18, 3, 7, 15, 9, 15, -35, -2, -1, 23, -17, 7, 18, -2, 11, -4, 20, 3, 19, 4, 25, 11, -15, 8, -14, 7, 1, -15, 30, 9, -2, 8, 12, 0, 0, 1, 28, 14, 21, 8, 9, -15, 14, -4, -10, -10, 10, 15, 2, 22, 19, 19, 19, 10, 5, -3, 3, 7, 6, 1, -8, -8, 8, -10, 11, 8, 5, 31, 18, -3, 7, 11, 11, -6, 0, -8, 16, 31, -3}

#define TENSOR_CONV2D_13_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_13_BIAS_0 {-10, -7, -10, -25, 8, 7, 5, -67}

#define TENSOR_CONV2D_13_BIAS_0_DEC_BITS {6}

#define CONV2D_13_BIAS_LSHIFT {6}

#define CONV2D_13_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_14_KERNEL_0 {-6, -26, 0, -27, 15, 17, -3, 26, -35, -1, 29, 25, 7, 12, 22, -66, 15, 24, 30, -23, -12, -5, 0, -53, 2, -8, -4, 0, -15, 26, 37, -35, 8, -33, -17, 34, -26, -1, 12, 5, -1, 3, 20, -23, -18, 18, 5, -15, -30, -10, -2, -38, -5, 4, 31, -23, 38, -27, -6, -29, 2, 3, 4, -19, -7, -9, -4, -7, -5, 5, -8, 3, -5, 5, -9, -11, 1, -13, -8, -9, 4, 62, -9, 5, -6, -21, 32, -15, -9, 60, 15, -27, -21, 8, 9, 2, 10, 32, 18, 16, 5, -9, 1, 16, 3, 65, 23, 8, 16, -17, 14, 41, 11, 19, -22, 5, -8, 0, -7, 28, 0, -47, 20, 22, 8, -7, -4, -7}

#define TENSOR_CONV2D_14_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_14_BIAS_0 {12, 7, 28, 20, -19, 23, -79, -20}

#define TENSOR_CONV2D_14_BIAS_0_DEC_BITS {7}

#define CONV2D_14_BIAS_LSHIFT {2}

#define CONV2D_14_OUTPUT_RSHIFT {5}

#define TENSOR_CONV2D_15_KERNEL_0 {2, -27, -20, -47, 0, -34, 6, -6, 21, -30, -1, 6, -10, -46, -11, 3, 21, 16, -21, 13, -2, -35, -81, -31, -19, -9, 9, 2, -7, 10, -71, -48, -6, 5, -17, -20, 5, 17, -65, -1, 21, 21, -14, -14, -1, -28, -68, -36, -57, -42, 11, -4, 2, 14, -1, -20, -31, 9, -6, -1, -6, 12, 10, -3, 4, 9, -12, -49, 5, -4, -112, -27, 18, 27, -15, 2, -8, -18, -24, -48, 7, -17, -16, -27, 0, -41, 3, 5, 28, -21, 2, -23, 7, -74, -15, 6, 14, 7, -29, -7, -13, 17, 3, -9, -19, -25, 0, -4, 13, 6, 5, 9, 17, 6, -39, -21, 4, 21, 3, -6, -56, -32, -3, -8, 0, 11, -2, 16}

#define TENSOR_CONV2D_15_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_15_BIAS_0 {69, -74, -3, -68, -46, 57, -102, -35}

#define TENSOR_CONV2D_15_BIAS_0_DEC_BITS {8}

#define CONV2D_15_BIAS_LSHIFT {1}

#define CONV2D_15_OUTPUT_RSHIFT {7}

#define TENSOR_DENSE_3_KERNEL_0 {-15, 8, -27, -24, 0, 6, 8, 5, -19, -24, 10, 5, 10, 6, 5, -14, -26, -25, 1, -4, 6, 3, -4, -27, -10, 9, -1, -6, 6, 8, -6, -23, -70, -61, -65, -30, -58, -54, -39, -40, -26, 9, 6, -12, 5, -12, -26, -27}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_3_BIAS_0 {-38, -1, -92, -19, 126, 12}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {6}

#define DENSE_3_BIAS_LSHIFT {0}

#define DENSE_3_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_12_INPUT_OUTPUT_DEC 9
#define CONV2D_12_INPUT_OUTPUT_OFFSET 0
#define CONV2D_12_OUTPUT_DEC 7
#define CONV2D_12_OUTPUT_OFFSET 0
#define RE_LU_12_OUTPUT_DEC 7
#define RE_LU_12_OUTPUT_OFFSET 0
#define CONV2D_13_OUTPUT_DEC 4
#define CONV2D_13_OUTPUT_OFFSET 0
#define RE_LU_13_OUTPUT_DEC 4
#define RE_LU_13_OUTPUT_OFFSET 0
#define CONV2D_14_OUTPUT_DEC 4
#define CONV2D_14_OUTPUT_OFFSET 0
#define RE_LU_14_OUTPUT_DEC 4
#define RE_LU_14_OUTPUT_OFFSET 0
#define CONV2D_15_OUTPUT_DEC 2
#define CONV2D_15_OUTPUT_OFFSET 0
#define RE_LU_15_OUTPUT_DEC 2
#define RE_LU_15_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_3_OUTPUT_OFFSET 0
#define FLATTEN_3_OUTPUT_DEC 2
#define FLATTEN_3_OUTPUT_OFFSET 0
#define DROPOUT_3_OUTPUT_DEC 2
#define DROPOUT_3_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 1
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

const nnom_shape_data_t tensor_conv2d_12_kernel_0_dim[] = {6, 2, 1, 8};
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

const nnom_shape_data_t tensor_conv2d_12_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_13_kernel_0_data[] = TENSOR_CONV2D_13_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_13_kernel_0_dim[] = {4, 2, 8, 8};
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

const nnom_shape_data_t tensor_conv2d_13_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_14_kernel_0_data[] = TENSOR_CONV2D_14_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_14_kernel_0_dim[] = {2, 1, 8, 8};
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

const nnom_shape_data_t tensor_conv2d_14_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_15_kernel_0_data[] = TENSOR_CONV2D_15_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_15_kernel_0_dim[] = {2, 1, 8, 8};
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

#endif //MODEL_39_NNOM_H