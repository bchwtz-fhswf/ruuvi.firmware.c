#ifndef MODEL_61_NNOM_H
#define MODEL_61_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_61_nnom
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
#define TENSOR_CONV2D_21_KERNEL_0 {-2, 5, 3, 20, -18, -80, 2, 69, 4, -51, 4, 32, -10, -3, 23, 0, -8, -5, -5, 4, -19, 40, 71, -61, 41, -27, 11, -7, -24, 43, -38, 31, -21, -11, -2, -9, -16, -19, -35, 13, -116, 6, -39, 3, 9, -14, 0, -4, 2, 11, 16, -7, -17, -18, -60, -73, 5, -2, -9, -11, 23, -14, 53, 42, -2, 1, 34, -10, 55, -14, 60, -10, -7, 46, -19, 39, 7, 70, -13, 32, 43, -4, 18, 4, 2, -30, 6, -16, -18, -5, -29, 7, 107, 14, -37, -3}

#define TENSOR_CONV2D_21_KERNEL_0_DEC_BITS {9}

#define TENSOR_CONV2D_21_BIAS_0 {-38, -3, -18, -75, 3, -38, -56, -25, -75, -31, 34, -15}

#define TENSOR_CONV2D_21_BIAS_0_DEC_BITS {5}

#define CONV2D_21_BIAS_LSHIFT {4}

#define CONV2D_21_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_22_KERNEL_0 {5, 0, -6, -42, 10, 0, -15, -6, -14, 1, 14, -7, -12, -4, -11, -4, 4, 0, -2, -9, -7, 0, 9, 3, -22, 8, -6, -13, 0, 3, -16, -11, 3, 6, 22, -8, -18, -11, -14, -1, -26, -40, -5, -7, 7, -15, -20, 27, -4, -3, 4, 17, -6, 17, -2, -11, -12, -21, 13, 15, -7, 11, 0, 8, -18, -18, -5, -9, -29, -21, -16, 17, -7, 15, -9, 20, 9, -7, 2, 18, -8, -9, 28, -25, -36, 1, -9, -11, 9, -4, 4, 9, 2, 7, -24, -24, -41, 5, -1, 2, -16, 1, -34, 6, 23, -12, -11, -25, 0, -17, -1, -7, 14, -115, -3, -12, -6, 7, 7, -1, -17, 8, -46, -22, -8, -60, -12, 4, 6, 19, 25, -72, -16, -15, -81, -81, -6, -63, -64, -12, 63, -6, 9, -59, 17, 2, 15, 5, 8, -2, 17, 12, 25, 12, 0, 16, 5, 3, -7, -4, -1, 11, -6, -4, -9, 2, -3, 16, -9, -1, 2, 8, 4, 9, 3, 2, 4, 3, 12, -1, -28, -36, -13, -37, -11, -12, 18, -19, 15, 33, -20, -31, -20, -20, -33, -18, -8, -4, 12, -6, -2, 2, 12, -39, 17, 0, -23, 9, 15, -7, 18, 3, 34, 21, 2, 2, -1, 0, -2, -3, -2, -7, -2, 0, 9, 2, -6, 11, -6, -5, -5, -8, -8, 10, -4, -5, 0, -11, -10, -3, 10, 0, 12, 14, 12, 9, 20, 15, 8, 16, 8, 0, 17, 10, 12, -9, 5, -22, 6, 15, -9, -7, -3, 19, 9, -2, 7, -3, 15, 17, -12, 2, -2, 14, 26, 12, -9, -3, -4, -43, -10, -14, -25, -28, -31, -10, -15, -6}

#define TENSOR_CONV2D_22_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_22_BIAS_0 {67, 5, 15, 30, -42, 18, -13, 13}

#define TENSOR_CONV2D_22_BIAS_0_DEC_BITS {5}

#define CONV2D_22_BIAS_LSHIFT {3}

#define CONV2D_22_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_23_KERNEL_0 {8, -23, 20, 28, -71, 12, -11, -79, 33, 22, 13, 47, -26, -2, -39, 31, 18, -20, 17, 2, 11, 7, -3, -10, 29, 7, 4, -7, -25, 5, -16, -11, -1, 3, 21, 82, -23, 17, 1, -52, -28, -12, 16, -31, -9, 3, 26, -6, -28, 3, -27, 15, 9, 14, -48, -19, 23, -14, -15, 33, -51, 17, -48, -6, -30, 3, -19, 5, -12, -4, 20, 3, 23, 12, -2, -57, -3, -39, -6, 0, 32, -47, 2, -65, -27, 22, -10, -1, 1, -32, -78, 5, -9, 8, 11, 30, -47, -12, -30, -36, -18, 0, 17, -13, -37, -24, -13, 21, -4, 1, -31, -4, 28, -5, 5, -37, 16, -95, 9, -11, 25, 5, 3, 44, -2, -1, 11, -6}

#define TENSOR_CONV2D_23_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_23_BIAS_0 {14, 98, -30, 21, 122, -22, -24, -82}

#define TENSOR_CONV2D_23_BIAS_0_DEC_BITS {6}

#define CONV2D_23_BIAS_LSHIFT {0}

#define CONV2D_23_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_7_KERNEL_0 {-8, 42, 8, -17, -25, -21, -13, -34, -19, -48, -7, 1, -22, -6, 3, -51, -29, -19, -19, 8, 13, 22, 8, -4, -21, -29, 36, 38, -39, -28, -5, -12, 25, 19, 27, 71, -20, -62, -79, -62, -17, 8, -1, -53, 3, -17, -1, -13}

#define TENSOR_DENSE_7_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_7_BIAS_0 {-87, -43, 64, 36, 13, 4}

#define TENSOR_DENSE_7_BIAS_0_DEC_BITS {6}

#define DENSE_7_BIAS_LSHIFT {1}

#define DENSE_7_OUTPUT_RSHIFT {5}


/* output q format for each layer */
#define CONV2D_21_INPUT_OUTPUT_DEC 0
#define CONV2D_21_INPUT_OUTPUT_OFFSET 0
#define CONV2D_21_OUTPUT_DEC 2
#define CONV2D_21_OUTPUT_OFFSET 0
#define RE_LU_21_OUTPUT_DEC 2
#define RE_LU_21_OUTPUT_OFFSET 0
#define MAX_POOLING2D_14_OUTPUT_DEC 2
#define MAX_POOLING2D_14_OUTPUT_OFFSET 0
#define CONV2D_22_OUTPUT_DEC 0
#define CONV2D_22_OUTPUT_OFFSET 0
#define RE_LU_22_OUTPUT_DEC 0
#define RE_LU_22_OUTPUT_OFFSET 0
#define MAX_POOLING2D_15_OUTPUT_DEC 0
#define MAX_POOLING2D_15_OUTPUT_OFFSET 0
#define CONV2D_23_OUTPUT_DEC 1
#define CONV2D_23_OUTPUT_OFFSET 0
#define RE_LU_23_OUTPUT_DEC 1
#define RE_LU_23_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_7_OUTPUT_DEC 1
#define GLOBAL_MAX_POOLING2D_7_OUTPUT_OFFSET 0
#define DENSE_7_OUTPUT_DEC 2
#define DENSE_7_OUTPUT_OFFSET 0
#define SOFTMAX_7_OUTPUT_DEC 7
#define SOFTMAX_7_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_21_input_config = {
    .super = {.name = "conv2d_21_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_21_kernel_0_data[] = TENSOR_CONV2D_21_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_21_kernel_0_dim[] = {4, 2, 1, 12};
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

const nnom_shape_data_t tensor_conv2d_21_bias_0_dim[] = {12};
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
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_14_config = {
    .super = {.name = "max_pooling2d_14"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_22_kernel_0_data[] = TENSOR_CONV2D_22_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_22_kernel_0_dim[] = {3, 1, 12, 8};
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

const nnom_shape_data_t tensor_conv2d_22_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {3, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_15_config = {
    .super = {.name = "max_pooling2d_15"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_23_kernel_0_data[] = TENSOR_CONV2D_23_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_23_kernel_0_dim[] = {2, 1, 8, 8};
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

const nnom_shape_data_t tensor_conv2d_23_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_7_config = {
    .super = {.name = "global_max_pooling2d_7"},
    .output_shift = 0,
};
const int8_t tensor_dense_7_kernel_0_data[] = TENSOR_DENSE_7_KERNEL_0;

const nnom_shape_data_t tensor_dense_7_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_7_kernel_0_dec[] = TENSOR_DENSE_7_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_7_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_7_kernel_0 = {
    .p_data = (void*)tensor_dense_7_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_7_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_7_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_7_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_7_bias_0_data[] = TENSOR_DENSE_7_BIAS_0;

const nnom_shape_data_t tensor_dense_7_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_7_bias_0_dec[] = TENSOR_DENSE_7_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_7_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_7_bias_0 = {
    .p_data = (void*)tensor_dense_7_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_7_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_7_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_7_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_7_output_shift[] = DENSE_7_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_7_bias_shift[] = DENSE_7_BIAS_LSHIFT;
const nnom_dense_config_t dense_7_config = {
    .super = {.name = "dense_7"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_7_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_7_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_7_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_7_bias_shift
};

const nnom_softmax_config_t softmax_7_config = {
    .super = {.name = "softmax_7"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_7_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_21_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_21_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_14_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_22_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_15_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_23_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_7_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_7_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_7_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_61_NNOM_H