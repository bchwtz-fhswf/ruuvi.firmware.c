#ifndef MODEL_5_NNOM_H
#define MODEL_5_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_5_nnom
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
#define TENSOR_GRU_33_GRU_CELL_33_KERNEL_0 {48, 62, -5, 1, -2, -1, -43, -22, 2, 15, -9, -40, 53, 21, 55, -43, -64, -13, 18, -36, -14, 33, -6, 16, 34, 19, -27, -22, 59, 5, 18, -8, -10, 18, 0, 79, 23, -29, -7, 59, -67, -5, -2, 79, -32, -19, 42, 8, -42, 59, 57, 37, 13, -38, -39, -34, -1, -6, 2, 10, 38, 4, 16, -15, 45, 31, -58, 44, 6, 10, -9, 1}

#define TENSOR_GRU_33_GRU_CELL_33_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_33_GRU_CELL_33_RECURRENT_KERNEL_0 {41, 5, 35, -27, 84, 21, 33, -5, -33, 42, 16, 32, -43, 37, -67, -6, -16, -4, -54, 24, -14, -21, -61, 59, -48, 24, -10, -28, 4, -9, -17, 76, 39, -23, -8, 66, -43, 35, -34, 33, 59, -40, 15, 9, 72, -70, 8, -56, -2, 92, -20, -11, 16, 15, 99, -45, 36, -31, -32, 30, 99, -27, -46, 51, 4, 18, -11, -28, -35, -33, -4, 3, -45, -7, 47, 84, 63, 32, 33, -18, -58, 14, 0, 20, 25, -5, -7, -18, -18, 34, 15, -43, -54, -41, -44, -32, 59, 49, 8, -5, 21, 28, -20, -22, -20, 15, 7, 17, 0, -1, 21, 26, 6, -16, -23, -3, 12, -7, 91, -26, 43, 41, 19, -18, -1, 27, -7, -4, 29, -17, -19, 8, -40, -9, 21, -44, 6, 4, 13, 22, 40, 11, -28, 34, -34, -20, 3, 15, 12, -66, 45, 1, 10, -50, 14, -17, 13, -3, -5, -23, -22, -1, 26, 39, 15, 4, 6, 6, 14, -40, 20, 0, -15, 31, -12, 34, -6, -38, 43, 3, 21, -1, 29, -9, -13, -31, 16, 13, 12, 22, 14, 10}

#define TENSOR_GRU_33_GRU_CELL_33_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_33_GRU_CELL_33_BIAS_0 {61, 59, -84, -54, -45, -37, 2, -16, -13, -7, 7, 8, 2, 24, -46, -1, -8, 3, 1, -3, 11, 2, -4, -12, 61, 59, -84, -54, -45, -37, 2, -16, -13, -7, 7, 8, 2, 24, -46, -1, -6, -7, -22, 18, 6, -10, 1, -1}

#define TENSOR_GRU_33_GRU_CELL_33_BIAS_0_DEC_BITS {6}

#define GRU_33_BIAS_LSHIFT {7}

#define GRU_33_OUTPUT_RSHIFT {6}

#define TENSOR_GRU_34_GRU_CELL_34_KERNEL_0 {3, -39, 16, -10, 12, -12, -14, -61, 4, 58, 32, 31, 1, 14, 14, 14, -22, -7, 16, 20, 4, -24, 2, 14, 6, 23, -42, -6, 33, 93, 25, 31, -7, 1, 10, 6, -9, -13, -13, 10, -8, 55, -1, -10, 10, -11, 33, 13, 21, 15, 26, 19, 23, 13, 8, 63, -23, -15, -12, -16, 5, 38, -19, -26, 4, 13, -17, 7, 17, 11, -23, -4, 25, -27, 2, -11, -10, -2, -10, 12, -12, -7, 1, 10, -22, 13, -4, -39, 7, -4, -3, 17, 11, 28, 25, 18}

#define TENSOR_GRU_34_GRU_CELL_34_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_34_GRU_CELL_34_RECURRENT_KERNEL_0 {-16, -50, -40, -20, -16, -10, 33, 17, -38, -37, -40, -75, -13, -2, 4, 14, -37, -1, -21, -19, -41, 3, -11, -47, -14, -2, -43, -43, -31, -2, 39, -18, -10, 26, -19, 8, -17, 6, 41, 26, -3, 3, -44, 40, 17, 6, 19, 36}

#define TENSOR_GRU_34_GRU_CELL_34_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_34_GRU_CELL_34_BIAS_0 {-30, -11, -12, 8, 19, -64, 8, -91, -33, -11, 2, 21, -30, -11, -12, 8, 19, -64, 8, -91, -15, -3, 5, 11}

#define TENSOR_GRU_34_GRU_CELL_34_BIAS_0_DEC_BITS {7}

#define GRU_34_BIAS_LSHIFT {4}

#define GRU_34_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_35_GRU_CELL_35_KERNEL_0 {-32, -20, -4, 2, -95, -5, 11, -23, -48, -14, -18, -5, 24, 9, -14, 2, -14, -19, -6, 27, 76, 62, -5, 24, -19, 51, -25, -11, -9, 43, 0, 13, 20, -23, 10, -4, -5, -23, -21, -7, 22, 10, 17, 14, 5, 7, -12, -10}

#define TENSOR_GRU_35_GRU_CELL_35_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_35_GRU_CELL_35_RECURRENT_KERNEL_0 {70, 9, 38, -8, -4, -1, -48, -2, -18, -15, 24, -20, 11, -7, 15, -15, -28, 59, 11, 25, 14, -11, 26, 28, -1, -18, 26, 4, 5, -102, 21, -1, 8, -34, -35, 42, 4, -19, -20, -2, 13, -9, -33, 9, -10, -2, -33, 31}

#define TENSOR_GRU_35_GRU_CELL_35_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_35_GRU_CELL_35_BIAS_0 {76, 96, 105, 101, 2, -5, 34, -5, -20, -29, -16, -1, 76, 96, 105, 101, 2, -5, 34, -5, -19, 11, -23, 36}

#define TENSOR_GRU_35_GRU_CELL_35_BIAS_0_DEC_BITS {6}

#define GRU_35_BIAS_LSHIFT {5}

#define GRU_35_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_11_KERNEL_0 {32, 20, -15, -11, 20, -31, -11, -35, -10, -58, -67, 29, 23, 12, 11, 17, -28, -32, 53, -23, -34, 48, 38, 12}

#define TENSOR_DENSE_11_KERNEL_0_DEC_BITS {4}

#define TENSOR_DENSE_11_BIAS_0 {44, -33, 19, -74, 18, 27}

#define TENSOR_DENSE_11_BIAS_0_DEC_BITS {6}

#define DENSE_11_BIAS_LSHIFT {5}

#define DENSE_11_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define GRU_33_INPUT_OUTPUT_DEC 9
#define GRU_33_INPUT_OUTPUT_OFFSET 0
#define GRU_33_OUTPUT_DEC 7
#define GRU_33_OUTPUT_OFFSET 0
#define GRU_34_OUTPUT_DEC 7
#define GRU_34_OUTPUT_OFFSET 0
#define GRU_35_OUTPUT_DEC 7
#define GRU_35_OUTPUT_OFFSET 0
#define DENSE_11_OUTPUT_DEC 4
#define DENSE_11_OUTPUT_OFFSET 0
#define SOFTMAX_11_OUTPUT_DEC 7
#define SOFTMAX_11_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {9};
const nnom_qformat_param_t tensor_Placeholder_0_offset[] = {0};
const nnom_tensor_t tensor_Placeholder_0 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_Placeholder_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_Placeholder_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_Placeholder_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t gru_33_input_config = {
    .super = {.name = "gru_33_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_33_gru_cell_33_kernel_0_data[] = TENSOR_GRU_33_GRU_CELL_33_KERNEL_0;

const nnom_shape_data_t tensor_gru_33_gru_cell_33_kernel_0_dim[] = {3, 24};
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_kernel_0_dec[] = TENSOR_GRU_33_GRU_CELL_33_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_33_gru_cell_33_kernel_0 = {
    .p_data = (void*)tensor_gru_33_gru_cell_33_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_33_gru_cell_33_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_33_gru_cell_33_recurrent_kernel_0_data[] = TENSOR_GRU_33_GRU_CELL_33_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_33_gru_cell_33_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_recurrent_kernel_0_dec[] = TENSOR_GRU_33_GRU_CELL_33_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_33_gru_cell_33_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_33_gru_cell_33_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_33_gru_cell_33_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_33_gru_cell_33_bias_0_data[] = TENSOR_GRU_33_GRU_CELL_33_BIAS_0;

const nnom_shape_data_t tensor_gru_33_gru_cell_33_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_bias_0_dec[] = TENSOR_GRU_33_GRU_CELL_33_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_33_gru_cell_33_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_33_gru_cell_33_bias_0 = {
    .p_data = (void*)tensor_gru_33_gru_cell_33_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_33_gru_cell_33_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_33_gru_cell_33_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_33_gru_cell_config = {
    .super = {.name = "gru_33"},
    .weights = (nnom_tensor_t*)&tensor_gru_33_gru_cell_33_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_33_gru_cell_33_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_33_gru_cell_33_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_33_config = {
    .super = {.name = "gru_33"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_34_gru_cell_34_kernel_0_data[] = TENSOR_GRU_34_GRU_CELL_34_KERNEL_0;

const nnom_shape_data_t tensor_gru_34_gru_cell_34_kernel_0_dim[] = {8, 12};
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_kernel_0_dec[] = TENSOR_GRU_34_GRU_CELL_34_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_34_gru_cell_34_kernel_0 = {
    .p_data = (void*)tensor_gru_34_gru_cell_34_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_34_gru_cell_34_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_34_gru_cell_34_recurrent_kernel_0_data[] = TENSOR_GRU_34_GRU_CELL_34_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_34_gru_cell_34_recurrent_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_recurrent_kernel_0_dec[] = TENSOR_GRU_34_GRU_CELL_34_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_34_gru_cell_34_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_34_gru_cell_34_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_34_gru_cell_34_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_34_gru_cell_34_bias_0_data[] = TENSOR_GRU_34_GRU_CELL_34_BIAS_0;

const nnom_shape_data_t tensor_gru_34_gru_cell_34_bias_0_dim[] = {2, 12};
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_bias_0_dec[] = TENSOR_GRU_34_GRU_CELL_34_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_34_gru_cell_34_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_34_gru_cell_34_bias_0 = {
    .p_data = (void*)tensor_gru_34_gru_cell_34_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_34_gru_cell_34_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_34_gru_cell_34_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_34_gru_cell_config = {
    .super = {.name = "gru_34"},
    .weights = (nnom_tensor_t*)&tensor_gru_34_gru_cell_34_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_34_gru_cell_34_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_34_gru_cell_34_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 4
};

const nnom_rnn_config_t gru_34_config = {
    .super = {.name = "gru_34"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_35_gru_cell_35_kernel_0_data[] = TENSOR_GRU_35_GRU_CELL_35_KERNEL_0;

const nnom_shape_data_t tensor_gru_35_gru_cell_35_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_kernel_0_dec[] = TENSOR_GRU_35_GRU_CELL_35_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_35_gru_cell_35_kernel_0 = {
    .p_data = (void*)tensor_gru_35_gru_cell_35_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_35_gru_cell_35_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_35_gru_cell_35_recurrent_kernel_0_data[] = TENSOR_GRU_35_GRU_CELL_35_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_35_gru_cell_35_recurrent_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_recurrent_kernel_0_dec[] = TENSOR_GRU_35_GRU_CELL_35_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_35_gru_cell_35_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_35_gru_cell_35_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_35_gru_cell_35_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_35_gru_cell_35_bias_0_data[] = TENSOR_GRU_35_GRU_CELL_35_BIAS_0;

const nnom_shape_data_t tensor_gru_35_gru_cell_35_bias_0_dim[] = {2, 12};
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_bias_0_dec[] = TENSOR_GRU_35_GRU_CELL_35_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_35_gru_cell_35_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_35_gru_cell_35_bias_0 = {
    .p_data = (void*)tensor_gru_35_gru_cell_35_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_35_gru_cell_35_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_35_gru_cell_35_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_35_gru_cell_config = {
    .super = {.name = "gru_35"},
    .weights = (nnom_tensor_t*)&tensor_gru_35_gru_cell_35_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_35_gru_cell_35_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_35_gru_cell_35_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 4
};

const nnom_rnn_config_t gru_35_config = {
    .super = {.name = "gru_35"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_11_kernel_0_data[] = TENSOR_DENSE_11_KERNEL_0;

const nnom_shape_data_t tensor_dense_11_kernel_0_dim[] = {4, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_33_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_33_gru_cell_config), &gru_33_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_34_gru_cell_config), &gru_34_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_35_gru_cell_config), &gru_35_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_11_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_11_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_5_NNOM_H