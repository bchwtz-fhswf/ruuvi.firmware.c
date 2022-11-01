#ifndef MODEL_60_NNOM_H
#define MODEL_60_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_60_nnom
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
#define TENSOR_CONV2D_27_KERNEL_0 {-31, 19, -15, 28, 7, 20, 5, -2, 3, 1, 3, 4, 14, 8, 59, 13, 4, 2, 5, 0, 16, 36, 26, -32, 5, 5, 3, 8, 64, -23, -7, 12, -6, 5, -15, 5, -15, -7, -19, -74, -6, -27, -17, -31, 6, 16, -25, 3, 2, 50, -1, -36, -9, -6, -4, -42, 7, -23, 6, -36, -13, 42, 10, -6, 14, 28, 9, -7, 7, -11, 0, 24, -19, 14, -19, -16, 29, 20, -4, 2, -37, 5, 32, -22, 19, 24, 18, -28, 3, 2, 0, 3, -21, 51, -15, 32}

#define TENSOR_CONV2D_27_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_27_BIAS_0 {-59, -59, -53, -55, -52, -84, -10, -42, 81, -4, 0, -40}

#define TENSOR_CONV2D_27_BIAS_0_DEC_BITS {6}

#define CONV2D_27_BIAS_LSHIFT {2}

#define CONV2D_27_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_28_KERNEL_0 {-23, -1, -5, 7, 17, -11, -46, -1, 14, 13, -28, -26, -25, -10, 3, -10, 3, -42, 7, -42, -38, -11, 2, -51, 21, -47, 32, -8, -38, -33, -41, 22, -48, -25, -15, -25, -12, 19, 23, 26, 53, 7, -41, 12, -23, -7, -21, 10, 11, -13, 19, 15, 8, -19, -17, -32, -19, -1, -17, 17, -2, 23, 13, 2, 33, 0, 6, -22, 2, -7, 7, 0, -47, -35, -46, -42, 6, 33, 6, 36, -24, -25, 2, -46, -15, -21, -11, -15, -13, -23, -12, -30, 15, -34, -34, -16, 2, -24, 1, -33, -38, -8, -15, -21, 41, -33, -19, -60, 15, -6, -28, -28, -40, -36, 9, 15, -29, -44, 5, -23, 1, 36, 33, -41, -2, -10, 30, -22, -45, -36, -35, 35, -22, 32, -3, -36, -38, 2, -37, -23, 26, -41, -36, -13, -15, 25, 23, -14, -31, -2, -73, 26, -44, 20, -49, -6, -43, -14, -63, -23, -13, -22, -7, -26, -30, 22, -48, -56, -43, -39, 3, 13, 14, -37, -31, -23, 32, -1, 18, -69, -8, -39, -12, -27, -38, -25, 22, -12, 4, 11, 6, -27, -31, -8, -25, -9, -15, -32, 8, -4, 18, 18, 9, -5, -31, 1, 33, -7, 40, -14, 16, -8, 15, 8, 16, 2, -39, -32, -16, -36, -7, 0, -46, -29, -25, 18, -20, -46, -18, -46, -11, -19, 8, -36, 18, -26, -22, -44, -2, 7, -6, -44, -38, -9, -17, -31, 9, -34, -15, 17, -29, 16, 13, -29, -19, -14, 20, -13, 6, 4, 38, 4, -10, -2, -21, -11, -8, -19, -27, -49, -19, -31, 23, -26, 5, -1, -26, -26, -33, -37, -10, -22, -7, 7, 9, 10, 9, -38}

#define TENSOR_CONV2D_28_KERNEL_0_DEC_BITS {7}

#define TENSOR_CONV2D_28_BIAS_0 {-8, -63, 57, -4, -1, 0, -12, 103}

#define TENSOR_CONV2D_28_BIAS_0_DEC_BITS {6}

#define CONV2D_28_BIAS_LSHIFT {2}

#define CONV2D_28_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_29_KERNEL_0 {-1, -1, 25, -2, -10, -35, -4, -10, 2, -2, -10, -12, -28, -9, -12, 42, -6, 21, 15, -7, 12, -36, -16, 18, -14, 0, -32, -16, -3, 9, 11, -5, 22, -4, -75, -5, -3, 4, -20, 18, 20, 17, 20, 2, -6, -6, 19, 25, -17, -29, 3, -16, 7, 18, 17, 1, -24, 5, -67, 6, 14, -14, -23, 18, 3, -11, 16, 17, 17, 9, -26, 24, -6, 11, 3, 31, -14, 7, -16, 15, -25, 30, -49, 25, -8, -25, -2, 13, 13, -19, -12, -4, 21, -11, -27, -50, 23, 10, 26, -17, -4, -15, -19, 31, 2, 12, 20, 1, -35, -33, -22, 24, -14, 0, -50, 11, -7, 5, 21, -60, 1, 11, 0, -2, 6, 17, -8, -8}

#define TENSOR_CONV2D_29_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_29_BIAS_0 {52, -6, -8, 16, -30, -40, 9, 39}

#define TENSOR_CONV2D_29_BIAS_0_DEC_BITS {6}

#define CONV2D_29_BIAS_LSHIFT {0}

#define CONV2D_29_OUTPUT_RSHIFT {3}

#define TENSOR_DENSE_9_KERNEL_0 {-8, -21, -3, 17, -8, 9, 16, -14, 35, 31, -16, 11, 17, 27, -1, 13, 33, -1, 6, 31, -29, -20, 4, -2, 45, 28, -23, -23, 19, 9, 21, 17, 66, 6, -35, -79, -2, -56, 34, -18, 24, 21, -13, -12, 28, 19, -17, 7}

#define TENSOR_DENSE_9_KERNEL_0_DEC_BITS {6}

#define TENSOR_DENSE_9_BIAS_0 {-39, -12, 6, 4, 64, -13}

#define TENSOR_DENSE_9_BIAS_0_DEC_BITS {6}

#define DENSE_9_BIAS_LSHIFT {3}

#define DENSE_9_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define CONV2D_27_INPUT_OUTPUT_DEC 0
#define CONV2D_27_INPUT_OUTPUT_OFFSET 0
#define CONV2D_27_OUTPUT_DEC 1
#define CONV2D_27_OUTPUT_OFFSET 0
#define RE_LU_27_OUTPUT_DEC 1
#define RE_LU_27_OUTPUT_OFFSET 0
#define MAX_POOLING2D_18_OUTPUT_DEC 1
#define MAX_POOLING2D_18_OUTPUT_OFFSET 0
#define CONV2D_28_OUTPUT_DEC 0
#define CONV2D_28_OUTPUT_OFFSET 0
#define RE_LU_28_OUTPUT_DEC 0
#define RE_LU_28_OUTPUT_OFFSET 0
#define MAX_POOLING2D_19_OUTPUT_DEC 0
#define MAX_POOLING2D_19_OUTPUT_OFFSET 0
#define CONV2D_29_OUTPUT_DEC 3
#define CONV2D_29_OUTPUT_OFFSET 0
#define RE_LU_29_OUTPUT_DEC 3
#define RE_LU_29_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_9_OUTPUT_DEC 3
#define GLOBAL_MAX_POOLING2D_9_OUTPUT_OFFSET 0
#define DENSE_9_OUTPUT_DEC 2
#define DENSE_9_OUTPUT_OFFSET 0
#define SOFTMAX_9_OUTPUT_DEC 7
#define SOFTMAX_9_OUTPUT_OFFSET 0

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

const nnom_io_config_t conv2d_27_input_config = {
    .super = {.name = "conv2d_27_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_27_kernel_0_data[] = TENSOR_CONV2D_27_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_27_kernel_0_dim[] = {4, 2, 1, 12};
const nnom_qformat_param_t tensor_conv2d_27_kernel_0_dec[] = TENSOR_CONV2D_27_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_27_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_27_kernel_0 = {
    .p_data = (void*)tensor_conv2d_27_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_27_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_27_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_27_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_27_bias_0_data[] = TENSOR_CONV2D_27_BIAS_0;

const nnom_shape_data_t tensor_conv2d_27_bias_0_dim[] = {12};
const nnom_qformat_param_t tensor_conv2d_27_bias_0_dec[] = TENSOR_CONV2D_27_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_27_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_27_bias_0 = {
    .p_data = (void*)tensor_conv2d_27_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_27_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_27_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_27_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_27_output_shift[] = CONV2D_27_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_27_bias_shift[] = CONV2D_27_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_27_config = {
    .super = {.name = "conv2d_27"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_27_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_27_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_27_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_27_bias_shift, 
    .filter_size = 12,
    .kernel_size = {4, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_18_config = {
    .super = {.name = "max_pooling2d_18"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_28_kernel_0_data[] = TENSOR_CONV2D_28_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_28_kernel_0_dim[] = {3, 1, 12, 8};
const nnom_qformat_param_t tensor_conv2d_28_kernel_0_dec[] = TENSOR_CONV2D_28_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_28_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_28_kernel_0 = {
    .p_data = (void*)tensor_conv2d_28_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_28_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_28_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_28_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_28_bias_0_data[] = TENSOR_CONV2D_28_BIAS_0;

const nnom_shape_data_t tensor_conv2d_28_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_28_bias_0_dec[] = TENSOR_CONV2D_28_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_28_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_28_bias_0 = {
    .p_data = (void*)tensor_conv2d_28_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_28_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_28_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_28_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_28_output_shift[] = CONV2D_28_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_28_bias_shift[] = CONV2D_28_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_28_config = {
    .super = {.name = "conv2d_28"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_28_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_28_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_28_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_28_bias_shift, 
    .filter_size = 8,
    .kernel_size = {3, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_pool_config_t max_pooling2d_19_config = {
    .super = {.name = "max_pooling2d_19"},
    .padding_type = PADDING_VALID,
    .output_shift = 0,
    .kernel_size = {2, 1},
    .stride_size = {2, 1},
    .num_dim = 2
};
const int8_t tensor_conv2d_29_kernel_0_data[] = TENSOR_CONV2D_29_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_29_kernel_0_dim[] = {2, 1, 8, 8};
const nnom_qformat_param_t tensor_conv2d_29_kernel_0_dec[] = TENSOR_CONV2D_29_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_29_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_29_kernel_0 = {
    .p_data = (void*)tensor_conv2d_29_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_29_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_29_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_29_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_29_bias_0_data[] = TENSOR_CONV2D_29_BIAS_0;

const nnom_shape_data_t tensor_conv2d_29_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_29_bias_0_dec[] = TENSOR_CONV2D_29_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_29_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_29_bias_0 = {
    .p_data = (void*)tensor_conv2d_29_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_29_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_29_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_29_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_29_output_shift[] = CONV2D_29_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_29_bias_shift[] = CONV2D_29_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_29_config = {
    .super = {.name = "conv2d_29"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_29_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_29_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_29_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_29_bias_shift, 
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};

const nnom_global_pool_config_t global_max_pooling2d_9_config = {
    .super = {.name = "global_max_pooling2d_9"},
    .output_shift = 0,
};
const int8_t tensor_dense_9_kernel_0_data[] = TENSOR_DENSE_9_KERNEL_0;

const nnom_shape_data_t tensor_dense_9_kernel_0_dim[] = {8, 6};
const nnom_qformat_param_t tensor_dense_9_kernel_0_dec[] = TENSOR_DENSE_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_kernel_0 = {
    .p_data = (void*)tensor_dense_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_9_bias_0_data[] = TENSOR_DENSE_9_BIAS_0;

const nnom_shape_data_t tensor_dense_9_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_dense_9_bias_0_dec[] = TENSOR_DENSE_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_9_bias_0 = {
    .p_data = (void*)tensor_dense_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_9_output_shift[] = DENSE_9_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_9_bias_shift[] = DENSE_9_BIAS_LSHIFT;
const nnom_dense_config_t dense_9_config = {
    .super = {.name = "dense_9"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_9_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_9_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_9_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_9_bias_shift
};

const nnom_softmax_config_t softmax_9_config = {
    .super = {.name = "softmax_9"}
};
static int8_t nnom_output_data[6] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {6};
const nnom_qformat_param_t tensor_output0_dec[] = {SOFTMAX_9_OUTPUT_DEC};
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

	layer[0] = input_s(&conv2d_27_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_27_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(maxpool_s(&max_pooling2d_18_config), layer[2]);
	layer[4] = model.hook(conv2d_s(&conv2d_28_config), layer[3]);
	layer[5] = model.active(act_relu(), layer[4]);
	layer[6] = model.hook(maxpool_s(&max_pooling2d_19_config), layer[5]);
	layer[7] = model.hook(conv2d_s(&conv2d_29_config), layer[6]);
	layer[8] = model.active(act_relu(), layer[7]);
	layer[9] = model.hook(global_maxpool_s(&global_max_pooling2d_9_config), layer[8]);
	layer[10] = model.hook(dense_s(&dense_9_config), layer[9]);
	layer[11] = model.hook(softmax_s(&softmax_9_config), layer[10]);
	layer[12] = model.hook(output_s(&output0_config), layer[11]);
	*state = model_compile(&model, layer[0], layer[12]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_60_NNOM_H