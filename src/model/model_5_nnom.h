#ifndef HAR_GRU_NNOM_H
#define HAR_GRU_NNOM_H

#define APP_ACTIVITY_MODEL_NAME har_GRU_nnom
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
static const float highpass_coefficients[] = {0.24075012569983611f, -0.24075012569983611f, 0.0f, 0.24074851273755382f, -0.0f, 0.25f, -0.5f, 0.25f, 0.49040304612512053f, -0.24075173866211835f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_GRU_9_GRU_CELL_9_KERNEL_0 {-19, 40, 25, -47, -2, -39, 3, -34, -11, 39, -52, 34, -38, -7, 33, -56, 43, 18, -102, 86, -12, 40, 20, -65, -28, 41, 19, 17, -90, 13, 1, 45, 11, 7, -13, 9, 33, 66, 21, -49, 93, -1, 57, 20, 17, -18, -19, -14, -43, -26, 51, -12, -20, -21, -37, 36, -2, -11, -1, -8, -8, 32, 40, 47, 39, 32, -55, 40, -5, 1, 0, -14}

#define TENSOR_GRU_9_GRU_CELL_9_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0 {-17, -23, 32, 22, 59, 25, 1, -12, -13, -6, -43, 29, -14, -37, 20, 20, -12, -7, -4, -14, 4, 45, 37, 32, 37, 20, -6, 9, 1, -26, -9, 8, -25, 0, -1, -24, -13, 36, 11, 18, -11, -3, 37, -19, -31, -10, 14, 41, 31, 12, -2, -6, 12, -14, 25, -2, 7, 16, -12, -42, -15, -3, 11, -29, 5, -13, -4, 4, 1, -7, -22, 12, -14, -25, 30, -33, 41, 12, 7, 17, 45, 21, 19, 7, -20, 4, 20, -23, -29, -6, 11, 7, 3, 17, 26, 22, 15, 8, -9, -5, 8, -3, 20, -18, 44, 4, -25, 4, -27, 14, -1, -18, -9, -16, -67, 7, -14, 12, -8, 31, -4, -25, -54, -11, -12, -20, -14, -6, -26, 16, 1, -8, -12, -17, 13, -25, 20, -20, -14, 16, 18, -5, -8, -14, 4, 8, 17, -5, -9, 12, 10, 1, 2, 13, -23, 31, 29, 28, 0, 7, 8, 15, -10, 34, 35, -6, -22, -28, 25, 21, -12, -9, -3, -13, 3, -14, -3, 1, -20, 7, 11, -8, 0, 34, 5, -1, -24, -14, 7, 9, 26, 8}

#define TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_9_GRU_CELL_9_BIAS_0 {-14, -32, -54, -32, -28, -69, -6, -37, -40, -4, -28, -28, -18, -28, -18, -29, 1, -4, -8, -3, -19, 2, 8, -3, -14, -32, -54, -32, -28, -69, -6, -37, -40, -4, -28, -28, -18, -28, -18, -29, 10, -12, 21, -14, 10, -11, 13, 4}

#define TENSOR_GRU_9_GRU_CELL_9_BIAS_0_DEC_BITS {5}

#define GRU_9_BIAS_LSHIFT {6}

#define GRU_9_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_10_GRU_CELL_10_KERNEL_0 {-12, 34, -68, -42, -9, -70, -6, 25, -22, -10, -15, -14, -9, 42, -12, -19, 34, 36, 20, -1, 6, 5, 19, -25, -4, -28, 11, 15, 13, -13, -3, -3, 12, -22, -31, 10, 34, 5, 13, 4, 2, 14, -36, 8, -17, -20, 39, -40, -26, -13, -3, -46, 27, -84, 97, -11, -3, -3, 8, 13, -27, -3, -6, 2, -3, -14, 8, 31, -21, 3, -17, 5, 13, 33, -14, -10, -18, 20, -15, -16, -30, -54, -21, -37, 6, -30, 37, -39, -3, -7, 5, -31, 61, 16, 17, -3}

#define TENSOR_GRU_10_GRU_CELL_10_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0 {17, 31, -4, 1, -3, -25, 2, -15, 23, -8, 21, -5, 1, 1, -4, -37, 8, 38, -32, -16, 1, 17, -30, -13, 46, 15, 25, 13, -4, -81, 14, 3, -13, -15, -9, -17, 11, -9, 15, 3, -36, 15, -19, -40, -10, 92, 41, -2}

#define TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_10_GRU_CELL_10_BIAS_0 {-30, -23, 91, -5, 15, 38, -99, -8, -18, 12, 48, 51, -30, -23, 91, -5, 15, 38, -99, -8, 24, 36, 17, -12}

#define TENSOR_GRU_10_GRU_CELL_10_BIAS_0_DEC_BITS {6}

#define GRU_10_BIAS_LSHIFT {5}

#define GRU_10_OUTPUT_RSHIFT {4}

#define TENSOR_GRU_11_GRU_CELL_11_KERNEL_0 {-30, 27, -22, 13, -12, 3, 10, 21, 27, 7, -17, -11, -13, -2, 26, 7, 52, 6, -83, -3, -46, -27, -41, -19, -76, -12, -15, -25, -24, 46, -31, 19, 16, 23, 76, 4, -31, -18, -21, 11, 16, 13, -31, 13, 9, 42, 22, 5}

#define TENSOR_GRU_11_GRU_CELL_11_KERNEL_0_DEC_BITS {4}

#define TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0 {13, -37, 20, 27, -4, -40, -12, -76, -17, -11, 48, -8, -29, -82, 26, 28, 3, 127, -16, -103, -58, -15, -36, -61, -12, -67, -17, -16, -91, 19, -23, 54, 14, -12, -26, 61, -11, 38, 2, 10, -18, 25, 58, 68, 15, -88, 49, -34}

#define TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_GRU_11_GRU_CELL_11_BIAS_0 {13, 64, 65, 12, -23, 2, -11, 10, -7, -17, 27, 31, 13, 64, 65, 12, -23, 2, -11, 10, -25, 7, 53, 1}

#define TENSOR_GRU_11_GRU_CELL_11_BIAS_0_DEC_BITS {5}

#define GRU_11_BIAS_LSHIFT {6}

#define GRU_11_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_3_KERNEL_0 {-14, 23, -55, 9, 0, 32, -71, 99, -63, -120, -118, -8, 49, 40, 22, 14, -115, -31, 39, -11, 8, 68, 11, 8}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_3_BIAS_0 {101, -3, -50, -35, 22, -7}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {6}

#define DENSE_3_BIAS_LSHIFT {6}

#define DENSE_3_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define GRU_9_INPUT_OUTPUT_DEC 7
#define GRU_9_INPUT_OUTPUT_OFFSET 0
#define GRU_9_OUTPUT_DEC 7
#define GRU_9_OUTPUT_OFFSET 0
#define GRU_10_OUTPUT_DEC 7
#define GRU_10_OUTPUT_OFFSET 0
#define GRU_11_OUTPUT_DEC 7
#define GRU_11_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 4
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[192] = {0};

const nnom_shape_data_t tensor_Placeholder_0_dim[] = {64, 3};
const nnom_qformat_param_t tensor_Placeholder_0_dec[] = {7};
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

const nnom_io_config_t gru_9_input_config = {
    .super = {.name = "gru_9_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_gru_9_gru_cell_9_kernel_0_data[] = TENSOR_GRU_9_GRU_CELL_9_KERNEL_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_kernel_0_dim[] = {3, 24};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_kernel_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_kernel_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_data[] = TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_dim[] = {8, 24};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_9_gru_cell_9_bias_0_data[] = TENSOR_GRU_9_GRU_CELL_9_BIAS_0;

const nnom_shape_data_t tensor_gru_9_gru_cell_9_bias_0_dim[] = {2, 24};
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_bias_0_dec[] = TENSOR_GRU_9_GRU_CELL_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_9_gru_cell_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_9_gru_cell_9_bias_0 = {
    .p_data = (void*)tensor_gru_9_gru_cell_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_9_gru_cell_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_9_gru_cell_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_9_gru_cell_config = {
    .super = {.name = "gru_9"},
    .weights = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_9_gru_cell_9_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 8
};

const nnom_rnn_config_t gru_9_config = {
    .super = {.name = "gru_9"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_10_gru_cell_10_kernel_0_data[] = TENSOR_GRU_10_GRU_CELL_10_KERNEL_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_kernel_0_dim[] = {8, 12};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_kernel_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_kernel_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_data[] = TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_10_gru_cell_10_bias_0_data[] = TENSOR_GRU_10_GRU_CELL_10_BIAS_0;

const nnom_shape_data_t tensor_gru_10_gru_cell_10_bias_0_dim[] = {2, 12};
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_bias_0_dec[] = TENSOR_GRU_10_GRU_CELL_10_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_10_gru_cell_10_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_10_gru_cell_10_bias_0 = {
    .p_data = (void*)tensor_gru_10_gru_cell_10_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_10_gru_cell_10_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_10_gru_cell_10_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_10_gru_cell_config = {
    .super = {.name = "gru_10"},
    .weights = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_10_gru_cell_10_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 4
};

const nnom_rnn_config_t gru_10_config = {
    .super = {.name = "gru_10"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_gru_11_gru_cell_11_kernel_0_data[] = TENSOR_GRU_11_GRU_CELL_11_KERNEL_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_kernel_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_kernel_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_data[] = TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_dim[] = {4, 12};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_recurrent_kernel_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_gru_11_gru_cell_11_bias_0_data[] = TENSOR_GRU_11_GRU_CELL_11_BIAS_0;

const nnom_shape_data_t tensor_gru_11_gru_cell_11_bias_0_dim[] = {2, 12};
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_bias_0_dec[] = TENSOR_GRU_11_GRU_CELL_11_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_gru_11_gru_cell_11_bias_0_offset[] = {0};
const nnom_tensor_t tensor_gru_11_gru_cell_11_bias_0 = {
    .p_data = (void*)tensor_gru_11_gru_cell_11_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_gru_11_gru_cell_11_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_gru_11_gru_cell_11_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_gru_cell_config_t gru_11_gru_cell_config = {
    .super = {.name = "gru_11"},
    .weights = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_gru_11_gru_cell_11_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .units = 4
};

const nnom_rnn_config_t gru_11_config = {
    .super = {.name = "gru_11"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {4, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&gru_9_input_config);
	layer[1] = model.hook(rnn_s(gru_cell_s(&gru_9_gru_cell_config), &gru_9_config), layer[0]);
	layer[2] = model.hook(rnn_s(gru_cell_s(&gru_10_gru_cell_config), &gru_10_config), layer[1]);
	layer[3] = model.hook(rnn_s(gru_cell_s(&gru_11_gru_cell_config), &gru_11_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_3_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_3_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_GRU_NNOM_H