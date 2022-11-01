#ifndef MODEL_56_NNOM_H
#define MODEL_56_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_56_nnom
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
#define TENSOR_CONV2D_51_KERNEL_0 {8, 3, 14, -5, 6, 8, -6, 24, -10, 111, -7, -40, 2, 13, 1, 50, 29, 9, 36, 12, 56, -10, -4, 15, -46, -55, -2, -13, 9, 9, -18, 6, -58, 5, 16, 1, -5, -7, 8, -12, -3, 33, -34, 32, 60, -6, -6, -2, 5, 0, 2, -2, -10, -24, -9, -2, -40, -32, -20, 49, 50, -75, -14, -10, -33, -12, 43, -13, 4, 3, -4, 3, 67, 68, -3, 0, 12, 13, -35, -8, 3, 17, 22, 23, -7, -14, -3, -2, 2, 3, 8, 0, 9, -3, -4, 10, 7, -7, 17, 3, -6, -12, -16, -45, 28, -88, -7, -25, -12, 10, -14, 10, 18, -19, 37, -5, -8, -6, 42, -8, -10, 11, -40, 34, -21, 21, -19, 20, 11, -8, 1, -2, -92, 10, -41, 14, -47, 24, -10, 6, -4, 5, 5, 0, -3, 32, 51, 2, -40, 15, 19, 1, 10, 5, -8, 0, -3, -6, 13, 5, 14, -3, 15, 1, 5, -3, -3, -4, -1, 13, 55, 57, 32, 28, 32, 35, 15, 51, -10, 33, 6, -8, 2, 0, -1, -1, 15, 1, 97, -7, 37, 4}

#define TENSOR_CONV2D_51_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_51_BIAS_0 {-64, -75, -55, -40, -41, -77, -13, 43, -63, -56, -58, -44, -5, -35, -65, -58}

#define TENSOR_CONV2D_51_BIAS_0_DEC_BITS {6}

#define CONV2D_51_BIAS_LSHIFT {3}

#define CONV2D_51_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_52_KERNEL_0 {-1, -36, -80, 1, -2, 11, 29, -6, -3, -24, -29, -6, 8, -34, 11, 4, -10, 9, -11, -34, -4, -8, 0, -21, -23, -13, -14, -12, -59, -22, -24, -38, -76, -27, -34, -17, -16, -22, -28, -8, -21, -6, -35, -11, -36, -27, -37, -31, -57, -5, -91, -5, -53, -19, -20, 3, -35, -17, -38, -18, -60, 0, -43, 30, -16, -6, -5, -6, 26, 0, 24, -29, 41, -11, -25, -20, 6, -28, 16, 23, -64, 44, -8, -23, -24, -4, -34, -31, -64, -4, -43, -8, -65, -28, -47, -6, -42, 26, 3, 20, -49, -14, -55, -8, 8, -22, 31, 6, -51, 3, -4, -63, -14, -11, -49, -16, -65, -29, -10, 4, 7, -18, 9, 12, -48, -6, 16, -62, -6, 30, -3, 29, 29, -15, -13, 2, 27, 18, 25, 6, -17, 7, 7, 25, 7, 28, 12, 18, -9, 11, 0, -4, 6, 1, 6, -5, -1, -4, 5, -2, 17, 4, 7, -22, -11, -3, -17, -13, 5, 14, -11, 27, 14, -3, -6, 12, 17, -4, 11, 3, 7, -3, -10, 4, 1, 6, -5, 17, 0, -2, -2, 6, 20, 0, -8, 2, 3, -21, 6, -6, -1, -9, 7, -2, -17, -3, -5, 16, 4, 7, 2, 2, -1, 6, -1, -11, 10, -13, 13, -25, -29, -1, 6, 4, 1, 15, 11, -9, 13, 14, 11, 2, 17, 12, -2, 22, 5, 13, 3, 22, 5, -3, -1, 0, 0, 12, -9, 3, 15, 0, 5, 15, 3, -3, 10, 5, 1, -37, 20, 8, 7, 18, 24, 22, 13, -11, -12, -4, 8, 9, 28, 5, -3, -24, 6, -7, 0, 4, 7, -4, -17, 8, 17, 14, 4, -5, 7, 5, 10, -10, -15, 14, 8, -75, 0, 27, 4, 14, -56, -45, -16, -23, -28, 5, -3, -4, -15, 8, 0, -86, -13, 12, -23, -2, -41, -40, -14, 5, -21, -10, 13, -6, -14, 2, 2, -16, -6, 18, 5, -4, 2, 0, 9, 7, -13, -10, 11, -3, 5, -13, -4, 9, -9, 8, 6, 2, 10, 0, 11, -3, -4, -6, -11, 0, -29, 9, -8, -3, 3, -6, -28, 1, -8, -7, -6, 8, -6, -43, -32, -5, -4, -12, -19, 2, 5, 19, -16, -16, -2, -9, -4, -8, -6, -18, -42, -60, -70, -16, -41, -57, -33, 35, -30, -49, -38, -1, -36, -35, -84, -19, -20, -9, -11, -8, -24, -23, -13, 35, -21, -16, -26, -42, -31, 5, -18, -15, 4, -5, -14, 9, -23, -63, -30, 9, -14, -29, -14, -30, -25, -27, -28, 13, 7, 1, -1, 7, 6, 8, -4, 2, -11, 4, -14, -43, 1, 9, 2, 16, -22, -18, -4, 19, -19, -43, -22, 25, 9, 4, 1, 1, -6, -4, 14, 6, -27, -12, -27, 11, -12, -11, -11, 31, 5, 4, 22, 3, 4, -11, 2, -17, -33, -21, 9, -36, 3, -14, 16, 34, -67, -59, -1, 20, 22, -26, -5, -64, -37, -24, 21, -32, -10, -13, -21, 37, 2, -27, 5, 6, 15, -12, -6, -29, 15, 12, -15, -12, 10, 29, -21, -26, -14, -19, 0, -4, 24, -22, -3, 13, -23, -39, 5, -13, -5, -15, 8, 4, -7, 18, 10, 11, -7, -5, -43, -3, -24, -29, -5, -1, -4, 22, 23, -26, 17, 10, -23, -7, 18, 2, -7, -27, -25, -23, -13, -5, -17, -22, -19, -29, -3, -27, -23, -16, 3, -4, -6, -45, -25, -21, 0, -27, -51, 16, 3, -24, -50, -44, -11, 8, -11, -29, -12, -65, -52, -29, -19, -21, 3, -6, 10, -31, -35, -40, 0, -4, 21, 1, -19, -57, 8, 26, 1, 33, -19, -36, 26, 9, 15, 24, 7, -25, -11, 9, 16, 8, -30, -26, -12, -21, 3, -56, 17, -3, -6, 12, -25, -17, 7, -10, -21, -11, 7, -4, -9, -8, 2, -8, 15, 23, -3, -19, 26, 15, -4, 6, -12, -32, -20, -12, -7, -31, 3, -5, -2, 4, -19, 7, 8, 9, -16, -10, -6, -23, 17, -15, -12, 9, -12, 0, -3, 8, 19, -28, -1, -23, -11, -17, 6, 12, -16, -8, -20, 17, 1, -20, -2, -11, -3, -19, 6, -9, -12, -14, -21, 24, -61, -22, -82, -46, -16, -34, -19, -14, -33, -46, -20, -25, -12, -1, -21, -10, -70, 4, -51, -12, -40, -47, -18, 5, -47, -29, -24, -24, -8, -24, -33, 15, -10, 18, 12, -8, 18, -31, -23, 5, 21, -5, -13, 15, 4, 0, 15, 16, 33, 17, 10, 7, 24, 1, 27, 8, 51, -19, -20, 18, -8, 1, 33, 11, -7, -4, -20, -32, -33, -46, -40, 9, -16, -44, -10, -23, -23, -19, -57, -23, -15, 10, -17, -29, -39, -2, -4, 22, -14, -28, -2, -29, -16, -11, -27, -19, 3, -25, -39, -48, -30, -43, -69, -7, -30, -30, -18, -55, -56, -7, -3, -48, -27, 12, -19, -20, -28, -31, -23, 6, -21, 7, -22, -20, -18, -30, 5, -46, -2, -17, -32, -44, 0, -13, -21, 21, -30, -21, -8, -19, -2, -16, -9, -30, -11, 10, -40, -29, -27, -5, -12, 11, -29, -27, -8, -37, -20, -13, 6, 3, -24, -7, -30, 4, -33, -1, -35, -7, -12, -20, -28, -41, -48, 1, -33, -48, -23, -4, -41, -8, -60, 7, -34, 10, -33, -42, -18, -31, -38, 2, -26, -34, -6, -49, 0, -41, -18, -25, -19, -1, -34, -26, -41, 18, -77, -10, -20, -53, 2, -6, -19, 6, -16, -27, -22, -1, -25, -45, -39, 0, 7, 1, -34, -13, 5, -28, -20, -1, -11, -1, -53, 8, -19, -7, -28, -37, -6, 5, -1, 15, -10, -10, -16, -20, -3, -1, -26, 43, 21, 4, 1, -7, -2, -24, -32, -26, -1, 7, -14, -27, -3, -20, -15, 36, 5, -14, 5, -11, 6, -17, -24, -20, -29, -34, -9, -45, -14, 7, -14, 24, -10, 0, 6, 9, 20, -16, -10, -38, -29, -36, -25, -5, -34, -22, 3, 17, -16, -49, 2, -25, -25, 13, -23, -21, 11, -23, -14, -25, -6, -42, 5, 29, -21, -15, -28, -3, 11, 19, -32, -20}

#define TENSOR_CONV2D_52_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_52_BIAS_0 {22, -95, 122, 108, -10, 48, 50, 25}

#define TENSOR_CONV2D_52_BIAS_0_DEC_BITS {7}

#define CONV2D_52_BIAS_LSHIFT {2}

#define CONV2D_52_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_53_KERNEL_0 {13, -30, 14, 40, 5, -5, 25, -11, -5, -13, 14, 34, 4, -2, 7, 28, 34, -9, 15, 6, -38, -21, 19, -24, -39, -4, 10, -6, 14, -2, 7, 26, 2, 12, 1, 27, 8, -9, -34, 1, -26, -10, 21, -56, 16, -12, -28, 15, 0, -1, -1, -15, -5, 19, 18, -52, 6, -1, -1, 4, -19, 6, -23, -11, -6, 11, 14, 27, 6, 7, -2, 21, 13, 19, 9, -20, -20, 9, -65, -42, 35, 17, 16, 33, -14, 13, 11, -15, 25, 9, 0, 9, -14, -21, 9, 10, -18, -25, 0, -41, -12, -32, -8, -22, -21, -50, 16, 15, 0, 1, 36, 28, -8, -26, -21, -13, 8, -10, 21, -4, -23, 11, 4, -19, 9, -3, 11, -10}

#define TENSOR_CONV2D_53_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_53_BIAS_0 {-8, 35, 28, 21, -21, -14, -5, 2}

#define TENSOR_CONV2D_53_BIAS_0_DEC_BITS {6}

#define CONV2D_53_BIAS_LSHIFT {0}

#define CONV2D_53_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_17_KERNEL_0 {15, 86, -25, -6, -23, -3, 57, 54, -42, -68, -38, -55, -8, 31, -15, 21, 20, 21, 47, 61, 10, -4, 5, -3, 17, 15, 72, -48, -32, -28, 29, 9, 97, 103, -99, -10, -90, 71, -95, -26, 24, -30, 53, 76, -21, -4, -23, 42}

#define TENSOR_DENSE_17_KERNEL_0_DEC_BITS {7}

#define TENSOR_DENSE_17_BIAS_0 {-71, -46, 14, 17, 87, 11}

#define TENSOR_DENSE_17_BIAS_0_DEC_BITS {8}

#define DENSE_17_BIAS_LSHIFT {1}

#define DENSE_17_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_51_INPUT_OUTPUT_DEC 0
#define CONV2D_51_INPUT_OUTPUT_OFFSET 0
#define CONV2D_51_OUTPUT_DEC 2
#define CONV2D_51_OUTPUT_OFFSET 0
#define RE_LU_51_OUTPUT_DEC 2
#define RE_LU_51_OUTPUT_OFFSET 0
#define MAX_POOLING2D_34_OUTPUT_DEC 2
#define MAX_POOLING2D_34_OUTPUT_OFFSET 0
#define CONV2D_52_OUTPUT_DEC 0
#define CONV2D_52_OUTPUT_OFFSET 0
#define RE_LU_52_OUTPUT_DEC 0
#define RE_LU_52_OUTPUT_OFFSET 0
#define MAX_POOLING2D_35_OUTPUT_DEC 0
#define MAX_POOLING2D_35_OUTPUT_OFFSET 0
#define CONV2D_53_OUTPUT_DEC 2
#define CONV2D_53_OUTPUT_OFFSET 0
#define RE_LU_53_OUTPUT_DEC 2
#define RE_LU_53_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_17_OUTPUT_DEC 2
#define GLOBAL_MAX_POOLING2D_17_OUTPUT_OFFSET 0
#define DENSE_17_OUTPUT_DEC 3
#define DENSE_17_OUTPUT_OFFSET 0
#define SOFTMAX_17_OUTPUT_DEC 7
#define SOFTMAX_17_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_51_input_config = {
    .super = {.name = "conv2d_51_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_51_kernel_0_data[] = TENSOR_CONV2D_51_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_51_kernel_0_dim[] = {6, 2, 1, 16};
const nnom_qformat_param_t tensor_conv2d_51_kernel_0_dec[] = TENSOR_CONV2D_51_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_51_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_51_kernel_0 = {
    .p_data = (void*)tensor_conv2d_51_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_51_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_51_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_51_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_51_bias_0_data[] = TENSOR_CONV2D_51_BIAS_0;

const nnom_shape_data_t tensor_conv2d_51_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_conv2d_51_bias_0_dec[] = TENSOR_CONV2D_51_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_51_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_51_bias_0 = {
    .p_data = (void*)tensor_conv2d_51_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_51_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_51_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_51_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_51_output_shift[] = CONV2D_51_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_51_bias_shift[] = CONV2D_51_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_51_config = {
    .super = {.name = "conv2d_51"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_51_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_51_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_51_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_51_bias_shift, 
    .filter_size = 16,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_34_config = {
    .super = {.name = "max_pooling2d_34"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_52_kernel_0_data[] = TENSOR_CONV2D_52_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_52_kernel_0_dim[] = {4, 2, 16, 8};
const nnom_qformat_param_t tensor_conv2d_52_kernel_0_dec[] = TENSOR_CONV2D_52_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_52_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_52_kernel_0 = {
    .p_data = (void*)tensor_conv2d_52_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_52_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_52_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_52_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_52_bias_0_data[] = TENSOR_CONV2D_52_BIAS_0;

const nnom_shape_data_t tensor_conv2d_52_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_52_bias_0_dec[] = TENSOR_CONV2D_52_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_52_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_52_bias_0 = {
    .p_data = (void*)tensor_conv2d_52_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_52_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_52_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_52_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_52_output_shift[] = CONV2D_52_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_52_bias_shift[] = CONV2D_52_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_52_config = {
    .super = {.name = "conv2d_52"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_52_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_52_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_52_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_52_bias_shift, 
    .filter_size = 8,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_35_config = {
    .super = {.name = "max_pooling2d_35"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_53_kernel_0_data[] = TENSOR_CONV2D_53_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_53_kernel_0_dim[] = {2, 1, 8, 8};
const nnom_qformat_param_t tensor_conv2d_53_kernel_0_dec[] = TENSOR_CONV2D_53_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_53_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_53_kernel_0 = {
    .p_data = (void*)tensor_conv2d_53_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_53_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_53_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_53_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_53_bias_0_data[] = TENSOR_CONV2D_53_BIAS_0;

const nnom_shape_data_t tensor_conv2d_53_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_53_bias_0_dec[] = TENSOR_CONV2D_53_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_53_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_53_bias_0 = {
    .p_data = (void*)tensor_conv2d_53_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_53_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_53_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_53_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_53_output_shift[] = CONV2D_53_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_53_bias_shift[] = CONV2D_53_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_53_config = {
    .super = {.name = "conv2d_53"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_53_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_53_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_53_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_53_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_17_config = {
    .super = {.name = "global_max_pooling2d_17"},
    .output_shift = 0,
};
const int8_t tensor_dense_17_kernel_0_data[] = TENSOR_DENSE_17_KERNEL_0;

const nnom_shape_data_t tensor_dense_17_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_17_kernel_0_dec[] = TENSOR_DENSE_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_17_kernel_0 = {
    .p_data = (void*)tensor_dense_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_17_bias_0_data[] = TENSOR_DENSE_17_BIAS_0;

const nnom_shape_data_t tensor_dense_17_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_17_bias_0_dec[] = TENSOR_DENSE_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_17_bias_0 = {
    .p_data = (void*)tensor_dense_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_17_output_shift[] = DENSE_17_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_17_bias_shift[] = DENSE_17_BIAS_LSHIFT;
const nnom_dense_config_t dense_17_config = {
    .super = {.name = "dense_17"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_17_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_17_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_17_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_17_bias_shift
};

const nnom_softmax_config_t softmax_17_config = {
    .super = {.name = "softmax_17"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_17_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_51_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_51_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_34_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_52_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_35_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_53_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_17_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_17_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_17_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_56_NNOM_H