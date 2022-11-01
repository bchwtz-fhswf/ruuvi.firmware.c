#ifndef MODEL_44_NNOM_H
#define MODEL_44_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_44_nnom
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
#define TENSOR_CONV2D_3_KERNEL_0 {-10, -29, -30, -31, 55, -20, -31, 18, -51, -7, -63, 8, 0, 10, -41, 54, 1, 11, -26, -20, -37, -31, -9, -30, -64, 25, -28, 5, 7, -48, 37, -21, -29, 17, 28, -26, 28, 30, 15, 48, -69, -16, -51, -6, -20, -30, -95, 13, 69, 68, -36, -12, -8, -76, 5, 19, -36, 40, -54, -28, 62, -19, -17, 12, -6, 31, -18, -33, 30, 4, 67, 25, -91, 13, -7, 20, 27, 8, 79, -23, 16, -7, -67, 28, -73, 16, 20, 66, -77, 1, -30, -9, -57, -4, 49, -71}

#define TENSOR_CONV2D_3_KERNEL_0_DEC_BITS {6}

#define TENSOR_CONV2D_3_BIAS_0 {41, 91, 99, 96, -14, 114, 31, 8}

#define TENSOR_CONV2D_3_BIAS_0_DEC_BITS {8}

#define CONV2D_3_BIAS_LSHIFT {7}

#define CONV2D_3_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_4_KERNEL_0 {9, 7, 8, -17, -26, -5, 11, 10, -30, -13, 0, -2, -28, 7, -76, 0, 2, 7, 14, 14, -4, 6, -13, 16, 2, -5, -7, -6, 6, 1, -18, 9, -5, -2, 6, 6, -11, -25, 8, 10, 9, -1, 2, 3, -6, 1, 4, 6, 8, 1, -12, 3, 12, 0, -15, 10, -8, 9, 2, 8, 22, 14, -2, 1, 0, 3, 4, -16, -14, 14, -4, 11, 5, -3, -6, 5, 6, -11, -10, 7, -10, 0, 2, 13, -13, 5, -9, -1, 1, 14, 11, 9, -28, 10, -13, -7, 13, 19, 9, 0, -8, 12, -2, -4, -6, -4, 0, -10, -7, 3, -14, 3, -4, 0, 12, -12, 5, 1, -1, 7, -9, -4, 1, -16, 13, 12, -3, 18}

#define TENSOR_CONV2D_4_KERNEL_0_DEC_BITS {4}

#define TENSOR_CONV2D_4_BIAS_0 {12, 102, -38, 35, -26, 70, 109, 54}

#define TENSOR_CONV2D_4_BIAS_0_DEC_BITS {8}

#define CONV2D_4_BIAS_LSHIFT {3}

#define CONV2D_4_OUTPUT_RSHIFT {7}

#define TENSOR_CONV2D_5_KERNEL_0 {10, 1, 11, 5, 6, -9, 3, 5, -8, -9, 16, 11, 4, -6, -13, -4, -16, -9, -9, -35, -46, 1, 9, -25, -2, 5, 4, -11, 8, 12, -2, -46, -4, -1, -11, -7, -1, 8, -7, -74, 32, 0, 3, -1, 21, -5, 5, 2, 8, 4, 10, 5, 6, -12, 5, 5, -15, -13, 17, 11, 10, -7, -14, -3, -8, -29, -1, -33, -6, -1, 8, -5, 11, 7, 12, -1, 16, 2, -3, -30, -8, 6, -1, -42, -35, 9, 9, -17, -8, -2, -5, -42, -21, 12, -5, -40, 4, -9, 13, 11, 7, 0, -21, 12, -9, 2, 2, 7, 27, -11, 3, 8, 5, -9, -30, -13, -27, 11, -8, -68, 30, 6, 4, -3, 9, 1, 4, 2}

#define TENSOR_CONV2D_5_KERNEL_0_DEC_BITS {4}

#define TENSOR_CONV2D_5_BIAS_0 {-50, 13, 23, -55, -67, 76, -118, -35}

#define TENSOR_CONV2D_5_BIAS_0_DEC_BITS {8}

#define CONV2D_5_BIAS_LSHIFT {0}

#define CONV2D_5_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_1_KERNEL_0 {13, 8, 5, 1, -24, -46, 2, -7, -19, 2, 13, 9, 9, 8, -21, -41, -19, 7, 12, 10, 2, -22, -20, -34, -27, -8, 10, 4, 0, 0, 7, 1, -36, -45, -67, -31, -116, -46, -42, -52, -34, 6, -2, -28, -36, -1, -25, 4}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_1_BIAS_0 {-42, -24, -21, 5, 68, 7}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {5}

#define DENSE_1_BIAS_LSHIFT {2}

#define DENSE_1_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define CONV2D_3_INPUT_OUTPUT_DEC 9
#define CONV2D_3_INPUT_OUTPUT_OFFSET 0
#define CONV2D_3_OUTPUT_DEC 7
#define CONV2D_3_OUTPUT_OFFSET 0
#define RE_LU_3_OUTPUT_DEC 7
#define RE_LU_3_OUTPUT_OFFSET 0
#define CONV2D_4_OUTPUT_DEC 4
#define CONV2D_4_OUTPUT_OFFSET 0
#define RE_LU_4_OUTPUT_DEC 4
#define RE_LU_4_OUTPUT_OFFSET 0
#define CONV2D_5_OUTPUT_DEC 3
#define CONV2D_5_OUTPUT_OFFSET 0
#define RE_LU_5_OUTPUT_DEC 3
#define RE_LU_5_OUTPUT_OFFSET 0
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_DEC 3
#define GLOBAL_MAX_POOLING2D_1_OUTPUT_OFFSET 0
#define FLATTEN_1_OUTPUT_DEC 3
#define FLATTEN_1_OUTPUT_OFFSET 0
#define DROPOUT_1_OUTPUT_DEC 3
#define DROPOUT_1_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 1
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

const nnom_io_config_t conv2d_3_input_config = {
    .super = {.name = "conv2d_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_conv2d_3_kernel_0_data[] = TENSOR_CONV2D_3_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_3_kernel_0_dim[] = {6, 2, 1, 8};
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_dec[] = TENSOR_CONV2D_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_kernel_0 = {
    .p_data = (void*)tensor_conv2d_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_3_bias_0_data[] = TENSOR_CONV2D_3_BIAS_0;

const nnom_shape_data_t tensor_conv2d_3_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_3_bias_0_dec[] = TENSOR_CONV2D_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_bias_0 = {
    .p_data = (void*)tensor_conv2d_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_3_output_shift[] = CONV2D_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_3_bias_shift[] = CONV2D_3_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_3_config = {
    .super = {.name = "conv2d_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_3_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_3_bias_shift, 
    .filter_size = 8,
    .kernel_size = {6, 2},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_4_kernel_0_data[] = TENSOR_CONV2D_4_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_4_kernel_0_dim[] = {2, 1, 8, 8};
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

const nnom_shape_data_t tensor_conv2d_4_bias_0_dim[] = {8};
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
    .filter_size = 8,
    .kernel_size = {2, 1},
    .stride_size = {1, 1},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_5_kernel_0_data[] = TENSOR_CONV2D_5_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_5_kernel_0_dim[] = {2, 1, 8, 8};
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
	nnom_layer_t* layer[12];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&conv2d_3_input_config);
	layer[1] = model.hook(conv2d_s(&conv2d_3_config), layer[0]);
	layer[2] = model.active(act_relu(), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_4_config), layer[2]);
	layer[4] = model.active(act_relu(), layer[3]);
	layer[5] = model.hook(conv2d_s(&conv2d_5_config), layer[4]);
	layer[6] = model.active(act_relu(), layer[5]);
	layer[7] = model.hook(global_maxpool_s(&global_max_pooling2d_1_config), layer[6]);
	layer[8] = model.hook(flatten_s(&flatten_1_config), layer[7]);
	layer[9] = model.hook(dense_s(&dense_1_config), layer[8]);
	layer[10] = model.hook(softmax_s(&softmax_1_config), layer[9]);
	layer[11] = model.hook(output_s(&output0_config), layer[10]);
	*state = model_compile(&model, layer[0], layer[11]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_44_NNOM_H