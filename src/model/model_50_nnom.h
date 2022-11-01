#ifndef MODEL_50_NNOM_H
#define MODEL_50_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_50_nnom
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
#define TENSOR_CONV2D_20_KERNEL_0 {-23, 47, -18, 46, 16, 19, -23, -64, 19, -84, 62, 16, 84, -35, -56, -15, -55, 5, -34, -18, 49, -2, 91, 13, 74, -26, 39, 13, -42, 68, -37, 36, 6, 29, 22, -92, -47, 56, 37, -17, -4, -33, 3, 10, -38, 39, -63, -58, -70, -12, 34, 0, -28, 17, -50, -10, -4, 16, 117, 40, 49, 80, 11, -16, -55, 31, -34, -102, -17, 7, 31, 89, 92, -28, 29, -57, -43, 62, 58, -25, -12, 14, -82, 65, -5, 44, -20, 51, -38, -11, 40, 20, -47, 40, -37, 55}

#define TENSOR_CONV2D_20_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_20_BIAS_0 {-11, -64, 19, -1, -70, -74, -96, 47}

#define TENSOR_CONV2D_20_BIAS_0_DEC_BITS {8}

#define CONV2D_20_BIAS_LSHIFT {7}

#define CONV2D_20_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_21_KERNEL_0 {-11, 25, 3, -35, -70, 0, -27, -19, -25, -85, 17, 17, -32, 15, 21, -10, 3, 50, 16, -14, -7, 13, -52, -5, -14, -69, 11, 10, -12, 20, 0, 1, 9, -12, -48, -4, -4, 21, 6, 1, -32, 6, 8, -5, -40, -15, -2, 12, 13, 29, -68, 1, -29, 53, -3, 20, -29, 14, -15, -38, -38, -14, 18, -5, -11, 60, 14, 1, 36, -28, -4, -30, -50, -73, -5, 10, -61, -16, 10, 8, 37, 3, -2, 14, 25, -2, 14, -15, -9, -48, 3, 15, 31, -1, 2, 3, 6, -18, -13, 2, -6, 33, 43, 0, -56, -5, 5, -7, -27, 15, -42, -6, 8, 10, 21, 15, 38, 34, 9, -3, 9, 12, -42, 16, -4, -27, 42, -1, 12, 19, 10, -6, 10, 41, 11, -21, -16, 36, 13, 5, -20, -8, 7, 3, 13, 43, -3, 26, 30, 8, 53, -21, 15, 12, 7, 7, 3, -39, 38, -5, 23, -24, 21, -5, 18, 21, 29, -11, -38, 20, 0, -1, -44, 1, 14, -36, 2, 10, 35, 10, 43, 4, 8, -5, -39, 12, 5, 20, 38, 17, 16, 7, 15, 9, 27, 19, 28, 3, 24, -1, -23, 9, 1, -16, 34, 11, 25, -32, 0, -4, -9, 4, 42, 9, 45, -1, 5, 9, 4, -11, 26, 5, 6, 13, -16, 18, 19, 26, -6, 41, 26, -6, 17, 42, -1, 6, 19, -12, 21, -11, 7, -22, -27, -3, 35, -4, 42, -15, 0, 1, 1, 5, 45, -23, 30, -12}

#define TENSOR_CONV2D_21_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_21_BIAS_0 {67, -43, -99, -107}

#define TENSOR_CONV2D_21_BIAS_0_DEC_BITS {7}

#define CONV2D_21_BIAS_LSHIFT {4}

#define CONV2D_21_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_22_KERNEL_0 {-22, 1, 1, 35, 3, 50, 28, -9, -27, 23, 7, -5, 32, -15, 23, 23, 11, -2, 29, -34, 27, 21, -79, -60, 46, -1, -30, -27, 21, 23, -3, -56}

#define TENSOR_CONV2D_22_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_22_BIAS_0 {19, 0, -108, 5}

#define TENSOR_CONV2D_22_BIAS_0_DEC_BITS {7}

#define CONV2D_22_BIAS_LSHIFT {2}

#define CONV2D_22_OUTPUT_RSHIFT {5}

#define TENSOR_CONV2D_23_KERNEL_0 {42, -88, -81, -36, 10, 34, -41, -34, 8, -8, -8, -34, 23, -23, -47, -11, -5, 11, 78, -17, -13, 6, 2, -63, -22, 8, 45, -16, -89, 0, 59, 19}

#define TENSOR_CONV2D_23_KERNEL_0_DEC_BITS {5}

#define TENSOR_CONV2D_23_BIAS_0 {-23, -66, 46, -51}

#define TENSOR_CONV2D_23_BIAS_0_DEC_BITS {8}

#define CONV2D_23_BIAS_LSHIFT {1}

#define CONV2D_23_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_5_KERNEL_0 {5, 4, 7, 12, -1, -3, -4, -60, 5, 2, -22, 2, -17, -31, 7, 1, -73, -33, -114, -85, -2, -25, -56, 0}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_5_BIAS_0 {-72, -65, -27, 14, 77, 19}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {6}

#define DENSE_5_BIAS_LSHIFT {1}

#define DENSE_5_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define CONV2D_20_INPUT_OUTPUT_DEC 9
#define CONV2D_20_INPUT_OUTPUT_OFFSET 0
#define CONV2D_20_OUTPUT_DEC 6
#define CONV2D_20_OUTPUT_OFFSET 0
#define RE_LU_20_OUTPUT_DEC 6
#define RE_LU_20_OUTPUT_OFFSET 0
#define CONV2D_21_OUTPUT_DEC 4
#define CONV2D_21_OUTPUT_OFFSET 0
#define RE_LU_21_OUTPUT_DEC 4
#define RE_LU_21_OUTPUT_OFFSET 0
#define CONV2D_22_OUTPUT_DEC 4
#define CONV2D_22_OUTPUT_OFFSET 0
#define RE_LU_22_OUTPUT_DEC 4
#define RE_LU_22_OUTPUT_OFFSET 0
#define CONV2D_23_OUTPUT_DEC 3
#define CONV2D_23_OUTPUT_OFFSET 0
#define RE_LU_23_OUTPUT_DEC 3
#define RE_LU_23_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_DEC 3
#define GLOBAL_MAX_POOLING2D_5_OUTPUT_OFFSET 0
#define FLATTEN_5_OUTPUT_DEC 3
#define FLATTEN_5_OUTPUT_OFFSET 0
#define DROPOUT_5_OUTPUT_DEC 3
#define DROPOUT_5_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 0
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_20_input_config = {
    .super = {.name = "conv2d_20_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_20_kernel_0_data[] = TENSOR_CONV2D_20_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_20_kernel_0_dim[] = {6, 2, 1, 8};
const nnom_qformat_param_t tensor_conv2d_20_kernel_0_dec[] = TENSOR_CONV2D_20_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_20_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_20_kernel_0 = {
    .p_data = (void*)tensor_conv2d_20_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_20_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_20_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_20_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_20_bias_0_data[] = TENSOR_CONV2D_20_BIAS_0;

const nnom_shape_data_t tensor_conv2d_20_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_20_bias_0_dec[] = TENSOR_CONV2D_20_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_20_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_20_bias_0 = {
    .p_data = (void*)tensor_conv2d_20_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_20_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_20_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_20_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_20_output_shift[] = CONV2D_20_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_20_bias_shift[] = CONV2D_20_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_20_config = {
    .super = {.name = "conv2d_20"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_20_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_20_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_20_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_20_bias_shift, 
    .filter_size = 8,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_21_kernel_0_data[] = TENSOR_CONV2D_21_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_21_kernel_0_dim[] = {4, 2, 8, 4};
const nnom_qformat_param_t tensor_conv2d_21_kernel_0_dec[] = TENSOR_CONV2D_21_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_21_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_21_kernel_0 = {
    .p_data = (void*)tensor_conv2d_21_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_21_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_21_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_21_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_21_bias_0_data[] = TENSOR_CONV2D_21_BIAS_0;

const nnom_shape_data_t tensor_conv2d_21_bias_0_dim[] = {4};
const nnom_qformat_param_t tensor_conv2d_21_bias_0_dec[] = TENSOR_CONV2D_21_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_21_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_21_bias_0 = {
    .p_data = (void*)tensor_conv2d_21_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_21_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_21_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_21_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_21_output_shift[] = CONV2D_21_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_21_bias_shift[] = CONV2D_21_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_21_config = {
    .super = {.name = "conv2d_21"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_21_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_21_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_21_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_21_bias_shift, 
    .filter_size = 4,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_22_kernel_0_data[] = TENSOR_CONV2D_22_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_22_kernel_0_dim[] = {2, 1, 4, 4};
const nnom_qformat_param_t tensor_conv2d_22_kernel_0_dec[] = TENSOR_CONV2D_22_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_22_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_22_kernel_0 = {
    .p_data = (void*)tensor_conv2d_22_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_22_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_22_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_22_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_22_bias_0_data[] = TENSOR_CONV2D_22_BIAS_0;

const nnom_shape_data_t tensor_conv2d_22_bias_0_dim[] = {4};
const nnom_qformat_param_t tensor_conv2d_22_bias_0_dec[] = TENSOR_CONV2D_22_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_22_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_22_bias_0 = {
    .p_data = (void*)tensor_conv2d_22_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_22_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_22_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_22_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_22_output_shift[] = CONV2D_22_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_22_bias_shift[] = CONV2D_22_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_22_config = {
    .super = {.name = "conv2d_22"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_22_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_22_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_22_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_22_bias_shift, 
    .filter_size = 4,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_23_kernel_0_data[] = TENSOR_CONV2D_23_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_23_kernel_0_dim[] = {2, 1, 4, 4};
const nnom_qformat_param_t tensor_conv2d_23_kernel_0_dec[] = TENSOR_CONV2D_23_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_23_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_23_kernel_0 = {
    .p_data = (void*)tensor_conv2d_23_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_23_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_23_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_23_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_23_bias_0_data[] = TENSOR_CONV2D_23_BIAS_0;

const nnom_shape_data_t tensor_conv2d_23_bias_0_dim[] = {4};
const nnom_qformat_param_t tensor_conv2d_23_bias_0_dec[] = TENSOR_CONV2D_23_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_23_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_23_bias_0 = {
    .p_data = (void*)tensor_conv2d_23_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_23_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_23_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_23_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_23_output_shift[] = CONV2D_23_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_23_bias_shift[] = CONV2D_23_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_23_config = {
    .super = {.name = "conv2d_23"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_23_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_23_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_23_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_23_bias_shift, 
    .filter_size = 4,
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

const nnom_flatten_config_t flatten_5_config = {
    .super = {.name = "flatten_5"}
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {4, 6};
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
	nnom_layer_t* layer[14];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_20_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_20_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_21_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_22_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_23_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_5_config), layer[8]);
	layer[10] = model.hook(flatten_s(&flatten_5_config), layer[9]);
	layer[11] = model.hook(dense_s(&dense_5_config), layer[10]);
	layer[12] = model.hook(softmax_s(&softmax_5_config), layer[11]);
	layer[13] = model.hook(output_s(&output0_config), layer[12]);
	*state = model_compile(&model, layer[0], layer[13]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_50_NNOM_H