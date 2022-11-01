#ifndef MODEL_58_NNOM_H
#define MODEL_58_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_58_nnom
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
#define TENSOR_CONV2D_39_KERNEL_0 {3, 8, -3, 1, -4, -7, -2, -51, -12, -36, 0, -7, 115, 1, 26, -3, 0, -3, 11, 0, -7, 1, -2, -6, 3, -1, 0, -1, -60, 9, 18, -4, 4, -3, -3, 6, 1, -1, 6, -6, 13, 11, -57, -5, -9, -5, -9, -2, -1, 1, -4, 3, 7, -2, 6, -2, 11, -10, 92, -26, 7, -9, -1, 82, -10, 9, 3, 3, -14, 6, -8, 0, -5, -2, -3, -4, 0, 1, -5, 34, -8, -54, -3, 13, 1, -11, -16, -15, -4, -12, -1, -12, 11, 5, -58, -57, 5, 47, -1, -66, -4, 15, -5, -1, 5, 13, 3, 2, -55, -62, -13, -23, -5, 3, -6, 2, -7, 9, 1, -5, 0, 7, 1, -14, -4, -4, 0, -16, -15, 46, -4, 64, 4, 2, -5, 3, -47, -1, -62, 10, -1, 10, 2, 6, 5, -4, 2, -5, 17, -8, 28, 2, -26, 53, 8, 0, -8, -3, -47, 7, 51, -13, -19, 16, -3, -3, -2, 3, 0, 0, -5, 2, -3, -5, 41, 2, 49, 8, 13, 9, -58, 50, -37, 31, -25, 11, -11, -4, -11, 0, -7, 3}

#define TENSOR_CONV2D_39_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_39_BIAS_0 {-71, -43, -62, -75, -59, -13, -34, -9, -2, 20, -1, -26, -58, -9, -58, -7}

#define TENSOR_CONV2D_39_BIAS_0_DEC_BITS {5}

#define CONV2D_39_BIAS_LSHIFT {4}

#define CONV2D_39_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_40_KERNEL_0 {5, -17, 25, 4, -3, -20, 8, -7, -5, -23, 11, -4, -5, -3, -4, -10, 12, -12, 2, 7, 7, -3, 6, -1, -8, -26, 16, -13, 10, -2, -5, -3, -20, -28, -9, 8, -6, 4, 4, -14, 5, 1, 2, -5, -23, 5, -17, -20, 5, 0, -2, -6, 21, 9, -1, -7, 12, 9, 1, -4, -1, 1, -8, -9, -32, 2, -25, -6, -19, -10, -2, 4, -7, -12, 0, 11, 11, -5, 4, -16, 20, -16, 22, -38, -16, -7, 7, 17, 9, 1, -8, 0, 15, -11, 9, 4, -2, -23, -9, -5, -30, 18, -4, -28, -7, -9, -1, -2, -4, 4, -11, 6, 10, -17, 3, 13, -1, 3, -19, -14, 5, -4, -11, 1, -1, 17, 2, -14, 9, -5, 5, 12, 13, 0, -1, 6, -6, -12, 2, 7, 2, 0, 11, -9, 13, -10, 6, 8, 6, -6, -2, -1, -6, -5, -7, 6, 1, 2, 2, -4, 5, 5, 0, 9, 11, 5, 4, 6, 2, 0, 5, 0, 8, -2, 2, 3, -1, 4, 5, 12, 9, 10, 2, 1, 5, -1, 4, -3, 0, -3, -3, 2, 10, -2, 6, 10, 7, 2, 1, 6, 3, 6, 3, 10, 9, -2, 6, 9, -2, -4, 3, 8, 3, 3, 0, -1, 0, -8, -1, 4, 1, -1, 4, -2, 2, 5, 10, 9, 3, 4, 5, 5, -3, -2, 5, 3, 8, 7, 11, -5, 1, 1, 6, 7, 11, 6, 7, 7, 3, 0, 6, 7, 8, 2, -2, -1, 8, -10, -4, -4, 7, 6, 6, 3, 7, -6, 10, -2, 16, 3, 14, -14, -2, -7, -16, -7, -8, -1, 9, -5, 2, -5, 9, 5, -1, -2, 2, -12, -2, -19, 16, 10, -4, 10, 1, 3, 1, -12, 1, 10, 2, 9, 7, -1, -12, -18, -7, -16, 5, 8, -5, -2, 1, 1, -9, 6, -5, 1, -12, -2, -1, 20, -17, -11, -18, 0, 2, 2, -2, 19, -5, -15, 0, 0, -16, 6, -40, 3, -18, -1, -8, 2, 1, -5, 6, 15, -8, -13, -10, -9, -8, 5, -4, -19, -7, -22, 10, 4, -7, 11, 9, -3, 7, -21, -17, 0, -23, -14, -19, -8, -8, -9, 14, 7, -7, 6, 7, 3, 13, -14, -20, 5, -12, -7, -12, -3, 12, 14, -11, -29, -25, -23, -16, -1, -9, -17, -63, -37, -28, -31, -28, -31, -32, 8, -69, -47, -30, -30, -30, -5, -4, -40, -2, -48, -6, -30, -32, -19, -59, 22, -6, 16, -28, 5, -13, 12, 2, -15, -3, -18, 3, -18, -12, -33, -30, -32, 12, -3, -27, -21, -19, 12, 11, -24, -44, -62, -18, -27, -6, 2, 24, 1, 9, -37, 9, -4, 6, 2, 4, 14, -5, -35, 15, -31, 16, 0, -1, -18, 8, 3, 5, -1, -6, 9, 12, -10, 15, -26, 12, -9, 5, 14, -3, -15, -15, -8, -3, -4, -14, 14, 3, -72, -1, 1, 12, -9, -8, 4, 3, 6, -70, -5, 7, -28, 10, 0, -11, -11, -46, -28, -37, -18, -10, 9, -24, 22, 7, -3, 3, 4, -2, -30, -26, 5, -38, -27, -8, -23, -16, -19, -10, 5, -27, -12, -11, 2, -34, -15, 3, 8, 2, -12, -25, -13, -10, -7, -5, -11, 2, -29, -24, -14, 8, -13, 11, 0, 6, -28, 7, -4, -10, -21, 0, 8, 9, -14, -25, 2, -11, -5, -7, 13, -39, -14, 6, -3, -7, 3, 5, -10, -29, -11, 1, -15, 9, 10, 3, 19, 8, -5, 14, 16, 1, -25, -4, -4, -5, -12, -3, -14, -17, 12, -4, -13, 2, -10, -3, 7, -3, 7, 6, -2, 12, 9, -5, -22, -4, -29, 5, -25, -18, -6, -7, 1, -11, 11, -38, -8, -20, -8, 2, -15, -16, -11, -8, -15, 7, -11, -21, -36, 0, -12, -28, 3, 8, -5, -9, -10, -16, 4, 11, -5, -30, -34, -4, -2, -24, -4, -12, -7, 2, -9, -22, -4, -17, -2, 17, 1, -15, -25, 3, 3, -7, -9, -18, -20, -46, 1, -12, -28, -10, -7, -8, 18, -8, -11, -7, -3, -2, -2, 3, -8, -23, -14, -23, -17, -25, -3, -14, 5, -17, -10, -13, 5, -9, 11, -19, -22, 10, 13, -11, 8, 8, 6, -1, -15, -4, 3, 9, 3, 7, 5, -15, -18, 9, 16, -8, 17, 6, 13, 16, -4, -1, -2, -1, 2, 0, -1, 1, 9, 11, 3, 9, 11, -1, 4, 8, 13, 13, -2, 4, 3, 13, -1, 6, 6, 15, -3, 22, 19, 3, 4, 20, 7, 14, 10, 12, 6, -6, 23, 0, 10, 1, 9, 3, -2, 2, -1, -5, 11, -14, -29, -6, -48, -14, 8, 1, -24, 7, 11, -4, 7, 4, 14, 6, -10, -1, 5, 4, 10, -3, 11, -5, -1, -3, -3, -5, -11, -24, 8, 5, -3, 4, -13, 2, -3, 0, -10, 7, 0, -13, -5, 3, -17, -12, 12, 1, -20, 17, -15, -1, 2, -10, -20, 4, -12, 14, -7, -2, -16, -7, 3, -28, 1, -33, -16, 5, 2, 2, 5, 5, 9, -33, 12, -12, -14, 5, 7, -6, -5, -24, 9, -18, -8, 9, -11, -39, -28, 4, -9, 3, 9, -26, -2, 3, -19, -2, -27, 15, 2, -1, 7, -7, 2, 8, -12, 12, 6, -13, 9, 12, -5, 15, -26, -6, -4, 1, 13, -8, -10, 5, 11, 3, -2, 11, 14, 2, -5, -1, -5, 6, 14, 2, 12, -4, 5, 12, 15, 3, 10, 15, 19, 13, -3, 7, -3, -5, 11, 5, -16, -3, 6, -18, 3, 2, -8, 1, -10, 1, 8, -2, 4, 4, -7, 15, -7, -3, 4, -6, -4, 13, 5, 0, -8, 11, 3, 7, 3, 13, -10, -12, 4, -8, -27, -20, 5, 6, 0, -3, -2, -1, -1, -4, 3, -13, 1, -13, 2, 0, -9, -4, 15, 5, 4, 7, 12, -3, 6, 5, 6, -2, 4, -6, -6, -7, -12, -4, -6, -8, 0, 3, -3, 0, -17, -9, 3, -10, -10, -5, 2, -13, -14, 0, -2, -7, 7, 10, 10, 5, -8, 0, 0, -4, -4}

#define TENSOR_CONV2D_40_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_40_BIAS_0 {34, -112, 112, 60, 11, 51, 7, 20}

#define TENSOR_CONV2D_40_BIAS_0_DEC_BITS {6}

#define CONV2D_40_BIAS_LSHIFT {2}

#define CONV2D_40_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_41_KERNEL_0 {-1, 23, -15, -31, 29, 12, 14, 11, 13, -26, -1, -17, 20, 4, 4, -20, -7, 14, -4, 28, 8, -22, 4, -22, -17, -11, 19, 25, -15, -30, 5, -10, -26, 15, -22, -30, 8, -34, 14, -1, 4, 14, -2, -33, -1, -27, 9, -6, 0, 7, 13, -64, 4, 7, -5, -18, 7, 3, 14, -56, -7, -9, -7, -1, 22, -69, 10, 41, 42, 16, -11, -11, 14, -66, 38, 37, 3, 8, 3, -36, -16, 3, 16, -22, 1, -2, 11, -19, -12, -6, -7, -14, 8, 22, 9, -12, 1, 3, -14, 49, 24, 5, 8, 0, 4, 13, -62, 33, 0, -2, 3, -19, -26, -34, -6, 3, 13, 3, 1, -21, 7, -16, -12, 41, 15, -7, 18, -7}

#define TENSOR_CONV2D_41_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_41_BIAS_0 {-10, 16, -94, 79, 30, -12, -53, 10}

#define TENSOR_CONV2D_41_BIAS_0_DEC_BITS {6}

#define CONV2D_41_BIAS_LSHIFT {0}

#define CONV2D_41_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_13_KERNEL_0 {16, -60, 28, 51, -67, -39, -4, -14, -11, -25, -36, 10, 18, -16, 41, 65, -23, 65, 40, 12, -100, -100, 14, -46, 47, 2, -27, -76, -15, -23, 67, -10, 4, 56, -37, -110, 73, 55, 26, 63, -24, -43, -38, 68, -54, 55, -4, -11}

#define TENSOR_DENSE_13_KERNEL_0_DEC_BITS {7}

#define TENSOR_DENSE_13_BIAS_0 {-94, -106, 41, 88, 67, -6}

#define TENSOR_DENSE_13_BIAS_0_DEC_BITS {7}

#define DENSE_13_BIAS_LSHIFT {0}

#define DENSE_13_OUTPUT_RSHIFT {4}


/* output q format for each layer */
#define CONV2D_39_INPUT_OUTPUT_DEC 0
#define CONV2D_39_INPUT_OUTPUT_OFFSET 0
#define CONV2D_39_OUTPUT_DEC 2
#define CONV2D_39_OUTPUT_OFFSET 0
#define RE_LU_39_OUTPUT_DEC 2
#define RE_LU_39_OUTPUT_OFFSET 0
#define MAX_POOLING2D_26_OUTPUT_DEC 2
#define MAX_POOLING2D_26_OUTPUT_OFFSET 0
#define CONV2D_40_OUTPUT_DEC -1
#define CONV2D_40_OUTPUT_OFFSET 0
#define RE_LU_40_OUTPUT_DEC -1
#define RE_LU_40_OUTPUT_OFFSET 0
#define MAX_POOLING2D_27_OUTPUT_DEC -1
#define MAX_POOLING2D_27_OUTPUT_OFFSET 0
#define CONV2D_41_OUTPUT_DEC 0
#define CONV2D_41_OUTPUT_OFFSET 0
#define RE_LU_41_OUTPUT_DEC 0
#define RE_LU_41_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_13_OUTPUT_DEC 0
#define GLOBAL_MAX_POOLING2D_13_OUTPUT_OFFSET 0
#define DENSE_13_OUTPUT_DEC 3
#define DENSE_13_OUTPUT_OFFSET 0
#define SOFTMAX_13_OUTPUT_DEC 7
#define SOFTMAX_13_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_39_input_config = {
    .super = {.name = "conv2d_39_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_39_kernel_0_data[] = TENSOR_CONV2D_39_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_39_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_39_kernel_0_dec[] = TENSOR_CONV2D_39_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_39_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_39_kernel_0 = {
    .p_data = (void*)tensor_conv2d_39_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_39_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_39_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_39_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_39_bias_0_data[] = TENSOR_CONV2D_39_BIAS_0;

const nnom_shape_data_t tensor_conv2d_39_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_39_bias_0_dec[] = TENSOR_CONV2D_39_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_39_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_39_bias_0 = {
    .p_data = (void*)tensor_conv2d_39_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_39_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_39_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_39_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_39_output_shift[] = CONV2D_39_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_39_bias_shift[] = CONV2D_39_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_39_config = {
    .super = {.name = "conv2d_39"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_39_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_39_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_39_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_39_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_26_config = {
    .super = {.name = "max_pooling2d_26"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_40_kernel_0_data[] = TENSOR_CONV2D_40_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_40_kernel_0_dim[] = {4, 2, 16, 8};
const nnom_qformat_param_t tensor_conv2d_40_kernel_0_dec[] = TENSOR_CONV2D_40_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_40_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_40_kernel_0 = {
    .p_data = (void*)tensor_conv2d_40_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_40_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_40_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_40_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_40_bias_0_data[] = TENSOR_CONV2D_40_BIAS_0;

const nnom_shape_data_t tensor_conv2d_40_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_40_bias_0_dec[] = TENSOR_CONV2D_40_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_40_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_40_bias_0 = {
    .p_data = (void*)tensor_conv2d_40_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_40_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_40_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_40_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_40_output_shift[] = CONV2D_40_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_40_bias_shift[] = CONV2D_40_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_40_config = {
    .super = {.name = "conv2d_40"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_40_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_40_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_40_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_40_bias_shift, 
    .filter_size = 8,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_27_config = {
    .super = {.name = "max_pooling2d_27"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_41_kernel_0_data[] = TENSOR_CONV2D_41_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_41_kernel_0_dim[] = {2, 1, 8, 8};
const nnom_qformat_param_t tensor_conv2d_41_kernel_0_dec[] = TENSOR_CONV2D_41_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_41_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_41_kernel_0 = {
    .p_data = (void*)tensor_conv2d_41_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_41_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_41_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_41_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_41_bias_0_data[] = TENSOR_CONV2D_41_BIAS_0;

const nnom_shape_data_t tensor_conv2d_41_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_41_bias_0_dec[] = TENSOR_CONV2D_41_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_41_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_41_bias_0 = {
    .p_data = (void*)tensor_conv2d_41_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_41_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_41_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_41_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_41_output_shift[] = CONV2D_41_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_41_bias_shift[] = CONV2D_41_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_41_config = {
    .super = {.name = "conv2d_41"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_41_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_41_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_41_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_41_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_13_config = {
    .super = {.name = "global_max_pooling2d_13"},
    .output_shift = 0,
};
const int8_t tensor_dense_13_kernel_0_data[] = TENSOR_DENSE_13_KERNEL_0;

const nnom_shape_data_t tensor_dense_13_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_13_kernel_0_dec[] = TENSOR_DENSE_13_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_13_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_13_kernel_0 = {
    .p_data = (void*)tensor_dense_13_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_13_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_13_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_13_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_13_bias_0_data[] = TENSOR_DENSE_13_BIAS_0;

const nnom_shape_data_t tensor_dense_13_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_13_bias_0_dec[] = TENSOR_DENSE_13_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_13_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_13_bias_0 = {
    .p_data = (void*)tensor_dense_13_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_13_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_13_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_13_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_13_output_shift[] = DENSE_13_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_13_bias_shift[] = DENSE_13_BIAS_LSHIFT;
const nnom_dense_config_t dense_13_config = {
    .super = {.name = "dense_13"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_13_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_13_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_13_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_13_bias_shift
};

const nnom_softmax_config_t softmax_13_config = {
    .super = {.name = "softmax_13"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_13_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_39_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_39_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_26_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_40_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_27_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_41_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_13_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_13_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_13_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_58_NNOM_H