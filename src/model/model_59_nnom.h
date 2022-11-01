#ifndef MODEL_59_NNOM_H
#define MODEL_59_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_59_nnom
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
#define TENSOR_CONV2D_33_KERNEL_0 {-7, -5, 2, -23, 51, 29, -10, -18, -9, 0, -8, -6, -18, 28, -4, -24, -11, 3, 7, -6, -8, 4, -1, -3, 16, -9, -19, 16, 1, -9, 9, 9, 34, 6, -46, -1, 24, -80, 12, 13, -3, 5, -2, -3, 7, 1, 3, -7, 47, 12, -30, 0, 36, 7, -18, 1, -4, -12, -6, -1, -14, 0, 2, 8, 13, -3, 23, -24, 41, 18, 38, -21, 31, 16, 31, 21, 18, 7, -3, -9, -25, 26, -14, 47, -87, 4, -45, 9, -15, 5, 25, 5, 15, -6, 8, 0, -5, -9, 5, 31, 8, 7, 2, 4, 9, 8, 22, 1, -20, -25, 6, -13, -29, 15, 23, -1, -26, -12, 4, 4, 0, -1, -3, -3, 3, -4, -1, -5, -61, 8, 1, 1, 6, -19, 3, -4, -4, 8, 1, 16, 0, 24, 0, 12, -23, -13, -21, -5, -2, 14, 3, -30, -13, 17, -35, -10, 4, -7, 6, 4, -1, -3, -11, 3, -27, -27, 1, -32, -19, 22, 18, -6, -1, 4, -37, 2, 29, 5, 7, 1, -20, 24, 23, -7, -11, 7, -9, 1, -3, -24, 6, 33}

#define TENSOR_CONV2D_33_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_33_BIAS_0 {-11, -8, -3, -76, -4, -22, -102, -45, -79, -3, -105, 78, -6, 79, 0, -96}

#define TENSOR_CONV2D_33_BIAS_0_DEC_BITS {6}

#define CONV2D_33_BIAS_LSHIFT {2}

#define CONV2D_33_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_34_KERNEL_0 {-3, -4, 7, 7, 13, -12, 23, -71, 13, -14, 7, -10, -14, 2, -17, -10, -3, 0, 8, 8, -15, -15, -8, 11, 11, 2, -1, 2, 5, -18, -8, 8, 19, -8, -49, 17, 4, 32, 38, 32, 7, -9, 34, -29, -40, 12, 11, 11, -6, 0, -21, 16, -1, 1, -2, 11, -2, -5, 30, -7, 7, -16, -1, -3, 4, 5, 8, 36, -14, 9, 2, 24, 12, -27, 15, -43, -17, -4, -47, -5, 5, 2, -4, 7, -7, 24, 5, 2, -5, 6, 6, -12, 3, -4, -5, 4, -33, -9, 5, -26, -30, 19, -15, -13, -28, -16, -14, 34, -3, 21, 10, -27, -29, -31, -25, -31, -31, 16, -20, -8, -54, -11, -8, 13, -19, 11, -22, -51, 9, -6, -30, -33, -5, -26, -9, -23, -35, -10, -56, 6, -9, -2, -25, -31, 15, -25, -26, -54, -14, -14, -25, -23, -21, -20, -39, 8, -28, -12, -17, -43, -11, 0, 15, 15, 1, 20, 0, 16, 25, 10, 17, 11, 19, 20, 2, 1, -7, 15, 13, 15, 16, 27, 45, 24, 4, -2, -4, 19, 14, 51, 7, 34, 7, -8, -16, -15, -10, -11, -28, -34, -28, 4, -5, -11, -10, -3, -27, 4, -14, -11, 13, 4, -16, 4, -27, 0, 13, -1, -13, 5, -27, -15, 10, 2, 3, -1, 18, 8, -20, -2, 17, 12, -7, 6, 2, -8, 6, 7, -36, 16, -1, -20, 14, 5, -11, -7, -4, -7, 17, -1, -11, -26, -1, 12, -34, 16, -22, -13, 13, -21, -21, 1, -2, -12, -32, -25, -23, -12, -14, -26, 2, -23, -6, -16, -26, -22, -3, -31, -31, -1, -18, -4, -12, -10, 9, -33, 7, -7, -27, -12, -4, 14, -17, 8, -6, -14, -21, -7, -19, -14, -5, -27, -14, 5, -16, -30, -26, 6, -31, -20, 10, -6, -5, -16, -23, -26, 13, -20, -7, -17, 11, -11, 1, -1, -14, -20, -8, 1, -1, -17, -4, -9, -17, -27, -22, -2, -33, -23, -15, -17, 0, -8, 9, -19, -26, 2, -24, 11, -15, 5, -16, -9, 9, -26, 3, 17, -14, 12, -4, -20, -21, -19, -20, 9, -6, -6, -18, 10, -20, -16, 18, 8, -10, -8, -21, -25, -36, 6, 0, 8, -2, -36, -16, -32, -16, 8, -21, -14, -25, -12, -21, -22, 3, 12, -8, -15, -8, -20, -9, 5, -27, -4, -2, 3, -23, 12, 6, -24, -11, -12, 3, 2, -7, -31, -18, 9, 12, -18, 10, 21, -30, -9, -13, -8, -10, -27, 16, -18, 1, -37, -18, 16, 8, 4, -30, 13, -15, -12, 15, -9, 9, -15, -23, -33, -38, -3, -24, -13, -22, -36, -4, 4, -26, -8, -4, 0, 6, 14, -18, -10, -4, -9, -36, 1, 13, -19, -35, -17, 8, -9, -4, 8, -6, 0, -25, -25, -13, 0, -22, -25, 11, 18, -11, -19, -6, 2, -32, 4, -14, -9, -16, -21, -16, -22, -4, -5, -2, 8, -14, -11, -8, -23, -1, -13, -9, -22, -2, -20, -19, -14, -32, -9, 8, 14, 12, -19, -24, -24, -5, -1, -17, -35, -34, 4, -27, -5, -31, -20, -31, -26, -23, -31, -19, 10, 15, -15, -25, 8, -11, -17, -3, -5, -22, -11, 13, -30, 10, -26, -29, -22, 0, -18, -22, -31, 15, 14, -27, -31, 7, -2, -6, -6, -1, -7, -28, -9, -1, -20, 11, -30, 7, -36, 10, 13, -1, -17, -63, -21, 3, -19, -13, -4, -6, -12, -35, -27, -90, 34, -33, 32, -12, -46, -33, -44, -38, -24, -51, -9, -15, 8, -12, -52, -95, 36, -42, 45, -30, -61, 4, -12, 12, -29, -4, 9, -1, -8, -1, -29, 4, 32, -3, 41, -5, -19, -46, -36, -10, -44, -37, 10, 3, -2, 1, -22, -67, 39, -21, 38, 7, -27, 9, -40, 15, 13, -28, 5, 11, 19, 1, -42, -6, 30, -38, 19, 5, -12, -18, 7, -13, -10, -31, -34, 24, 6, -32, -12, -16, 7, -31, 28, 10, -36, 9, 15, -30, 0, -63, 12, -35, -17, -42, -57, -25, 18, -17, 2, -33, -9, -35, -23, -23, 25, -44, -12, -2, -24, -46, 0, 1, 22, -10, -7, -42, 5, -13, -13, -40, -36, -42, -21, -3, -2, 5, -11, 8, 0, -31, 3, -32, -3, -3, -23, 9, 24, -60, -25, 22, -12, 11, 15, 5, 27, -9, -16, -23, -3, -66, -31, -49, -18, -5, -8, -23, -31, 16, -29, 2, 5, -25, -3, -3, -25, -2, -28, 6, -1, 22, -1, -14, 18, 4, 14, 10, 12, -59, 45, -36, -25}

#define TENSOR_CONV2D_34_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_34_BIAS_0 {-87, 54, -7, -4, -8, -7, 79, 24}

#define TENSOR_CONV2D_34_BIAS_0_DEC_BITS {6}

#define CONV2D_34_BIAS_LSHIFT {2}

#define CONV2D_34_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_35_KERNEL_0 {14, -30, 18, 20, -23, -22, 12, 0, 0, 0, 4, -16, -15, 26, -52, -21, -1, -1, -25, 18, -17, 3, 20, 20, 7, 2, -13, 21, -7, 21, 16, 23, 7, 1, -19, -1, 3, 4, 1, 11, -4, -32, -8, -14, -6, 11, 30, 9, 1, 1, 9, -28, 11, 20, 19, 1, -7, -23, 14, 3, 5, 3, -6, -21, 6, -53, -26, 1, 4, -24, -97, -21, -36, 6, 1, 7, 15, 10, -66, -27, 4, -6, -11, -16, 13, 19, 12, 8, 4, 4, -1, 11, 26, -5, 51, 7, 1, 7, 18, -16, -7, -2, -14, 11, -2, 22, -23, -26, -24, 27, -14, 36, -2, 20, -23, -26, -20, -23, -2, 0, 1, 2, 22, -9, -14, 22, -24, 3}

#define TENSOR_CONV2D_35_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_35_BIAS_0 {-81, 36, -10, -47, -62, -72, -34, 37}

#define TENSOR_CONV2D_35_BIAS_0_DEC_BITS {6}

#define CONV2D_35_BIAS_LSHIFT {0}

#define CONV2D_35_OUTPUT_RSHIFT {3}

#define TENSOR_DENSE_11_KERNEL_0 {20, -6, 3, 24, -15, -27, 3, 16, -55, -28, -21, -76, 12, -12, 13, -2, 20, 26, 46, -4, -26, -45, 1, -14, 33, 31, -24, -2, -53, -50, 6, 24, -97, 17, 45, 44, -38, 39, 18, -20, -33, -10, -18, -15, -26, -11, 7, 31}

#define TENSOR_DENSE_11_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_11_BIAS_0 {-42, -5, 31, 69, -127, 4}

#define TENSOR_DENSE_11_BIAS_0_DEC_BITS {6}

#define DENSE_11_BIAS_LSHIFT {2}

#define DENSE_11_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_33_INPUT_OUTPUT_DEC 0
#define CONV2D_33_INPUT_OUTPUT_OFFSET 0
#define CONV2D_33_OUTPUT_DEC 1
#define CONV2D_33_OUTPUT_OFFSET 0
#define RE_LU_33_OUTPUT_DEC 1
#define RE_LU_33_OUTPUT_OFFSET 0
#define MAX_POOLING2D_22_OUTPUT_DEC 1
#define MAX_POOLING2D_22_OUTPUT_OFFSET 0
#define CONV2D_34_OUTPUT_DEC -1
#define CONV2D_34_OUTPUT_OFFSET 0
#define RE_LU_34_OUTPUT_DEC -1
#define RE_LU_34_OUTPUT_OFFSET 0
#define MAX_POOLING2D_23_OUTPUT_DEC -1
#define MAX_POOLING2D_23_OUTPUT_OFFSET 0
#define CONV2D_35_OUTPUT_DEC 2
#define CONV2D_35_OUTPUT_OFFSET 0
#define RE_LU_35_OUTPUT_DEC 2
#define RE_LU_35_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_11_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_11_OUTPUT_OFFSET 0
#define DENSE_11_OUTPUT_DEC 3
#define DENSE_11_OUTPUT_OFFSET 0
#define SOFTMAX_11_OUTPUT_DEC 7
#define SOFTMAX_11_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_33_input_config = {
    .super = {.name = "conv2d_33_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_33_kernel_0_data[] = TENSOR_CONV2D_33_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_33_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_33_kernel_0_dec[] = TENSOR_CONV2D_33_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_33_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_33_kernel_0 = {
    .p_data = (void*)tensor_conv2d_33_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_33_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_33_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_33_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_33_bias_0_data[] = TENSOR_CONV2D_33_BIAS_0;

const nnom_shape_data_t tensor_conv2d_33_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_33_bias_0_dec[] = TENSOR_CONV2D_33_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_33_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_33_bias_0 = {
    .p_data = (void*)tensor_conv2d_33_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_33_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_33_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_33_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_33_output_shift[] = CONV2D_33_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_33_bias_shift[] = CONV2D_33_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_33_config = {
    .super = {.name = "conv2d_33"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_33_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_33_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_33_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_33_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_22_config = {
    .super = {.name = "max_pooling2d_22"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_34_kernel_0_data[] = TENSOR_CONV2D_34_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_34_kernel_0_dim[] = {3, 2, 16, 8};
const nnom_qformat_param_t tensor_conv2d_34_kernel_0_dec[] = TENSOR_CONV2D_34_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_34_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_34_kernel_0 = {
    .p_data = (void*)tensor_conv2d_34_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_34_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_34_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_34_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_34_bias_0_data[] = TENSOR_CONV2D_34_BIAS_0;

const nnom_shape_data_t tensor_conv2d_34_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_34_bias_0_dec[] = TENSOR_CONV2D_34_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_34_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_34_bias_0 = {
    .p_data = (void*)tensor_conv2d_34_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_34_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_34_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_34_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_34_output_shift[] = CONV2D_34_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_34_bias_shift[] = CONV2D_34_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_34_config = {
    .super = {.name = "conv2d_34"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_34_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_34_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_34_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_34_bias_shift, 
    .filter_size = 8,
    .kernel_size = {3, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_23_config = {
    .super = {.name = "max_pooling2d_23"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_35_kernel_0_data[] = TENSOR_CONV2D_35_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_35_kernel_0_dim[] = {2, 1, 8, 8};
const nnom_qformat_param_t tensor_conv2d_35_kernel_0_dec[] = TENSOR_CONV2D_35_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_35_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_35_kernel_0 = {
    .p_data = (void*)tensor_conv2d_35_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_35_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_35_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_35_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_35_bias_0_data[] = TENSOR_CONV2D_35_BIAS_0;

const nnom_shape_data_t tensor_conv2d_35_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_35_bias_0_dec[] = TENSOR_CONV2D_35_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_35_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_35_bias_0 = {
    .p_data = (void*)tensor_conv2d_35_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_35_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_35_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_35_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_35_output_shift[] = CONV2D_35_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_35_bias_shift[] = CONV2D_35_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_35_config = {
    .super = {.name = "conv2d_35"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_35_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_35_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_35_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_35_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_11_config = {
    .super = {.name = "global_max_pooling2d_11"},
    .output_shift = 0,
};
const int8_t tensor_dense_11_kernel_0_data[] = TENSOR_DENSE_11_KERNEL_0;

const nnom_shape_data_t tensor_dense_11_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_11_kernel_0_dec[] = TENSOR_DENSE_11_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_11_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_11_kernel_0 = {
    .p_data = (void*)tensor_dense_11_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_11_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_11_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_11_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_11_bias_0_data[] = TENSOR_DENSE_11_BIAS_0;

const nnom_shape_data_t tensor_dense_11_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_11_bias_0_dec[] = TENSOR_DENSE_11_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_11_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_11_bias_0 = {
    .p_data = (void*)tensor_dense_11_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_11_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_11_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_11_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_11_output_shift[] = DENSE_11_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_11_bias_shift[] = DENSE_11_BIAS_LSHIFT;
const nnom_dense_config_t dense_11_config = {
    .super = {.name = "dense_11"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_11_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_11_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_11_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_11_bias_shift
};

const nnom_softmax_config_t softmax_11_config = {
    .super = {.name = "softmax_11"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_11_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_33_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_33_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_22_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_34_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_23_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_35_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_11_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_11_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_11_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_59_NNOM_H