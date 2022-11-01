#ifndef MODEL_62_NNOM_H
#define MODEL_62_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_62_nnom
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
#define TENSOR_CONV2D_15_KERNEL_0 {24, -5, 33, -6, -5, -5, -30, -8, -22, -18, -3, 17, 11, -1, -9, 3, 16, -9, -78, 38, 73, -27, -2, -1, -16, -1, 2, -42, 25, 6, -10, -5, 16, 8, -34, -4, 24, 6, -38, -81, -6, 7, 8, 1, -10, 15, 6, -8, 1, 11, -17, 1, 2, -60, -1, -63, -6, 2, -3, -2, 2, -3, -29, 91, -6, 8, 4, 10, -5, -14, -14, 14, 1, -4, -4, -3, 25, 20, -44, -67, 20, 18, -2, 3, 97, 14, 49, 11, 18, 8, 12, 3, -2, -5, 5, -5, -7, -1, 3, -16, -12, 3, -19, 1, 10, 22, 22, 67, 8, -11, 8, -1, 55, 2, -12, -3, -88, 10, -82, 5, -92, 104, 3, 10, 4, 2, -1, -3, -12, 21, -8, 14, 16, -25, -4, 15, 8, -42, 1, 2, -9, 70, 4, -79, 37, 42, -12, -11, 0, 5, 13, -22, 2, 17, -2, -33, 16, 4, 70, -11, -8, -15, 1, 1, 11, -21, 13, -4, 7, -6, 6, -3, 6, -2, 1, -7, -4, -3, 70, -43, -63, -89, 6, -8, 4, 11, 1, 4, -7, -16, 6, 6}

#define TENSOR_CONV2D_15_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_15_BIAS_0 {53, -2, -94, -27, -98, -87, -11, -66, -98, -21, -19, -7, -2, -76, -14, -85}

#define TENSOR_CONV2D_15_BIAS_0_DEC_BITS {6}

#define CONV2D_15_BIAS_LSHIFT {3}

#define CONV2D_15_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_16_KERNEL_0 {-9, 10, 10, 19, 2, 23, 3, 14, 7, 12, 12, 5, -4, 15, 0, 5, -7, -2, 14, 18, -4, 27, 1, 1, 25, 4, 5, 9, 1, 13, 10, 12, 1, 3, 2, -3, 4, -1, 7, 12, 0, 1, 13, 5, 4, -8, -2, 16, -15, 3, 2, -2, 25, -1, 12, 10, -9, 8, 3, 3, 2, 0, -11, 4, -2, 3, 2, 1, -4, 8, 6, 9, 6, 8, 0, -9, -1, 16, 1, -3, -13, -6, 11, 11, 3, 25, -4, 8, 1, -8, 3, -4, -11, 2, 0, 11, 4, -84, 30, -3, 1, 6, -31, -35, -31, -82, -10, -21, -31, -20, -7, 9, 39, -42, -68, -20, -47, -55, -88, 14, -26, 44, -25, -28, -18, 11, -24, -12, 6, -64, -36, 33, 11, 63, 39, -113, -92, -57, -33, 6, 35, -44, -6, 9, 2, 23, 11, 4, -9, -36, -6, 1, -72, 22, -14, -55, -32, -43, 24, -1, 20, -91, -21, 18, 4, -12, -20, -13, -37, -66, -97, -42, -37, -25, -14, -13, 6, 10, -76, -3, -96, -40, -40, 26, -29, 18, 17, -84, -91, -24, -6, -7, 8, -23, -21, -45, -3, -14, -26, -2, -27, -10, -37, -8, -3, -24, -16, 30, 3, -15, -41, -44, -51, 6, -28, -6, -20, -36, 16, 12, -24, -17, 16, -30, -13, -9, -10, 2, -14, -24, -20, 17, 9, 9, -39, -15, -8, 18, -4, 8, -26, -28, -4, -12, -10, -17, -32, -11, 0, -26, -30, -1, -22, -21, 14, 0, -37, -4, -11, -51, 22, -10, -9, -2, 11, -8, 18, 5, -15, -21, -42, -24, -56, 17, 2, 2, -3, 19, -33, -24, -16, -11, -14, 19, -25, 4, -12, 9, 2, -16, 7, -19, 7, -11, -7, -79, -7, -28, -67, -4, -23, -50, 21, 0, -5, -22, 12, -28, -21, -40, -17, -46, 5, -9, -3, -50, -19, 3, 20, -16, -17, -13, -29, -30, -13, 13, 6, 7, 20, 0, -9, -49, -25, 31, -22, -27, -8, 25, -22, -14, -4, 17, 38, 9, -2, -3, 40, -10, 4, 19, 25, 13, -23, 3, -33, -24, 0, -20, -19, 3, -29, -1, 13, 34, -10, -58, -31, -58, -80, -38, -48, -7, -40, -19, -21, 25, -26, 2, -14, -2, -4, 36, -41, -48, 15, 8, -9, 22, -12, 3, 11, 18, -10, -9, 33, 5, 22, -5, 3, 15, -12, 12, 6, 15, -28, 7, 8, 33, -3, 5, 44, 17, 0, -3, 1, 50, -12, 6, 0, -15, -62, -7, 7, -54, 2, 7, -42, -13, -10, -21, 1, -46, -3, -12, 1, -10, -30, -12, -6, -49, 24, 11, -29, -1, 2, 7, 33, -34, -12, 17, -44, 10, -11, -27, 18, -18, -23, -3, -9, -19, -15, -7, -52, -26, -6, 30, -34, -7, -13, -29, 19, -45, -14, 10, -4, 13, 6, -2, -42, -9, -5, -4, -18, -21, 14, -8, -26, 2, 22, -9, 29, -6, -17, -23, 14, 15, -14, -7, -28, -53, -4, -49, -35, -14, 10, 26, -8, -27, -22, -27, -19, 1, 27, -13, -13, -17, 34, 17, -12, -3, -1, 1, -5, -48, -7, -6, 10, -3, -28, -35, -23, -17, -7, -22, -12, 1, -38, -11, -33, -43, -19, 1, -39, -68, 19, -32, 21, 18, 20, 3, -27, 23, 35, 36, 4, 6, -10, 6, -20, 18, 23, 7, 0, -11, 8, 3, -10, 25, 24, 24, -10, 7, 0, 2, 10, 28, -24, 19, -20, 12, -8, -11, 17, -8, 2, 13, -1, 10, 23, 8, 13, 5, -25, 6, 12, -6, -2, 7, 6, -15, -18, 18, -24, -13, -31, -4, 4, -24, -3, -19, -5, -11, 6, -3, 3, 3, 21, -4, 8, -10, -7, 2, 17, -3, -7, 17, -2, -14, 3, -14, 8, -28, -12, -20, -8, -23, -21, -2, 8, -4, 0, 23, 18, 16, 24, 9, 17, -5, 20, 10, 18, 29, 4, 22, 2, 20, 13, 5, 2, 0, -13, -13, 1, 16, -24, 35, -6, -20, -5, -15, 22, -5, 25, -37, 16, -13, 15, 20, -14, 26, 9, 2, -8, 7, -11, 36, 6, 26, -2, -4, 16, -6, 22, 26, -12, 17, 11, -17, 5, -29, 16, -20, 1, 28, 22, -58, 6, -45, 19, -22, -16, 10, -36, -48, 19, -52, -33, 25, -20, -15, 18, 24, -16, -3, 9, -33, -32, 7, -57, -20, -37, -31, -19, 11, 24, -12, 21, -106, -19, 1, 3, 25, -33, 16, 4, -45, 8, -49, -41, 21, -34, 9, 16, -74, -19, -21, 25, -42, -34, -5, -37, -18, -34, -88, -36, 15, 12, 4}

#define TENSOR_CONV2D_16_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_16_BIAS_0 {-96, 46, -11, 10, 48, -12, -58, 28}

#define TENSOR_CONV2D_16_BIAS_0_DEC_BITS {6}

#define CONV2D_16_BIAS_LSHIFT {2}

#define CONV2D_16_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_17_KERNEL_0 {-65, 73, -7, 34, -35, 43, -50, 31, -64, 99, -25, 8, 35, 19, -54, 83, -51, -38, 26, 36, -2, 10, -42, -30, -15, -31, 28, -16, 3, -18, -45, -21, 27, 69, -22, 57, 5, 16, -1, 65, -50, 93, 71, 19, -1, -7, -5, 76, 35, 9, -12, 42, -16, 0, 3, 52, -15, 52, 45, 1, -27, 22, -3, -58, -11, -87, 20, 13, -1, 19, -18, -40, 5, -29, 10, 24, 0, 19, 37, 22, -23, -9, -38, -24, -49, -10, 0, 6, 33, -22, 21, 35, 22, -25, 18, -21, 19, 37, 2, -87, 11, -24, -5, 6, 34, -25, -45, -30, -92, -89, 5, 21, -72, 66, 31, 17, 4, 21, -13, 27, 34, 92, -26, -12, -11, 9, 1, 13}

#define TENSOR_CONV2D_17_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_17_BIAS_0 {73, -29, 51, -76, -46, 61, -78, 9}

#define TENSOR_CONV2D_17_BIAS_0_DEC_BITS {6}

#define CONV2D_17_BIAS_LSHIFT {0}

#define CONV2D_17_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_5_KERNEL_0 {-10, 72, -12, -36, -53, -61, 2, 10, 24, -39, 42, 15, 21, -32, -14, -34, 33, 13, 10, 18, 18, -23, 0, 0, -23, -6, 2, -20, 10, 16, -24, -15, 50, -25, 26, 10, -1, -24, -24, 14, -44, -37, 11, -3, -10, 18, -13, 30}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_5_BIAS_0 {-63, -77, 56, 75, -71, 5}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {7}

#define DENSE_5_BIAS_LSHIFT {1}

#define DENSE_5_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_15_INPUT_OUTPUT_DEC 0
#define CONV2D_15_INPUT_OUTPUT_OFFSET 0
#define CONV2D_15_OUTPUT_DEC 1
#define CONV2D_15_OUTPUT_OFFSET 0
#define RE_LU_15_OUTPUT_DEC 1
#define RE_LU_15_OUTPUT_OFFSET 0
#define MAX_POOLING2D_10_OUTPUT_DEC 1
#define MAX_POOLING2D_10_OUTPUT_OFFSET 0
#define CONV2D_16_OUTPUT_DEC -1
#define CONV2D_16_OUTPUT_OFFSET 0
#define RE_LU_16_OUTPUT_DEC -1
#define RE_LU_16_OUTPUT_OFFSET 0
#define MAX_POOLING2D_11_OUTPUT_DEC -1
#define MAX_POOLING2D_11_OUTPUT_OFFSET 0
#define CONV2D_17_OUTPUT_DEC 2
#define CONV2D_17_OUTPUT_OFFSET 0
#define RE_LU_17_OUTPUT_DEC 2
#define RE_LU_17_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 3
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_15_input_config = {
    .super = {.name = "conv2d_15_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_15_kernel_0_data[] = TENSOR_CONV2D_15_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_15_kernel_0_dim[] = {6, 2, 1, 16};
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

const nnom_shape_data_t tensor_conv2d_15_bias_0_dim[] = {16};
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
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_10_config = {
    .super = {.name = "max_pooling2d_10"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_16_kernel_0_data[] = TENSOR_CONV2D_16_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_16_kernel_0_dim[] = {3, 2, 16, 8};
const nnom_qformat_param_t tensor_conv2d_16_kernel_0_dec[] = TENSOR_CONV2D_16_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_16_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_16_kernel_0 = {
    .p_data = (void*)tensor_conv2d_16_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_16_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_16_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_16_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_16_bias_0_data[] = TENSOR_CONV2D_16_BIAS_0;

const nnom_shape_data_t tensor_conv2d_16_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_16_bias_0_dec[] = TENSOR_CONV2D_16_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_16_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_16_bias_0 = {
    .p_data = (void*)tensor_conv2d_16_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_16_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_16_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_16_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_16_output_shift[] = CONV2D_16_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_16_bias_shift[] = CONV2D_16_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_16_config = {
    .super = {.name = "conv2d_16"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_16_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_16_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_16_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_16_bias_shift, 
    .filter_size = 8,
    .kernel_size = {3, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_11_config = {
    .super = {.name = "max_pooling2d_11"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_17_kernel_0_data[] = TENSOR_CONV2D_17_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_17_kernel_0_dim[] = {2, 1, 8, 8};
const nnom_qformat_param_t tensor_conv2d_17_kernel_0_dec[] = TENSOR_CONV2D_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_17_kernel_0 = {
    .p_data = (void*)tensor_conv2d_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_17_bias_0_data[] = TENSOR_CONV2D_17_BIAS_0;

const nnom_shape_data_t tensor_conv2d_17_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_17_bias_0_dec[] = TENSOR_CONV2D_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_17_bias_0 = {
    .p_data = (void*)tensor_conv2d_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_17_output_shift[] = CONV2D_17_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_17_bias_shift[] = CONV2D_17_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_17_config = {
    .super = {.name = "conv2d_17"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_17_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_17_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_17_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_17_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_5_config = {
    .super = {.name = "global_max_pooling2d_5"},
    .output_shift = 0,
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_5_kernel_0_dec[] = TENSOR_DENSE_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_kernel_0 = {
    .p_data = (void*)tensor_dense_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_5_bias_0_data[] = TENSOR_DENSE_5_BIAS_0;

const nnom_shape_data_t tensor_dense_5_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_5_bias_0_dec[] = TENSOR_DENSE_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_5_bias_0 = {
    .p_data = (void*)tensor_dense_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_5_output_shift[] = DENSE_5_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_5_bias_shift[] = DENSE_5_BIAS_LSHIFT;
const nnom_dense_config_t dense_5_config = {
    .super = {.name = "dense_5"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_5_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_5_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_5_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_5_bias_shift
};

const nnom_softmax_config_t softmax_5_config = {
    .super = {.name = "softmax_5"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_5_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_15_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_15_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_10_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_16_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_11_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_17_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_5_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_5_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_5_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_62_NNOM_H