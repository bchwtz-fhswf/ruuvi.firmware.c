#ifndef MODEL_20_NNOM_H
#define MODEL_20_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_20_nnom
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
#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0 {48, 22, 28, 14, -15, 51, 13, 41, 13, 47, -10, 2, -25, -51, -60, -30, 50, 19, 12, 7, -3, -22, -3, -8, 65, -43, -42, 22, -37, -4, -75, 25, 11, 21, 16, -14, -39, -49, 5, -15, 9, 46, 63, 30, -8, 10, -18, 31, -8, -8, -42, 21, -16, 12, 25, -33, 35, 4, -45, -41, -17, -18, 18, -42, -19, 38, 40, 46, 7, 6, 2, -4, 18, 52, 32, 48, -48, 36, -43, -26, 1, 30, 7, 4, 40, -44, -52, 40, -7, 19, 17, 62, 15, 15, -6, 5, -30, 27, 14, 31, 32, -30, 13, 4, 27, 14, 4, 18, 50, -45, -10, 2, 52, -34, -29, 18, -39, 37, 30, -16}

#define TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0 {-44, 28, 44, -3, -1, -13, -32, 36, 17, -43, -35, -3, -22, -50, 1, -68, -41, -24, -7, 4, 2, -17, 31, -79, -6, -8, 71, 25, 10, 29, -41, 83, 3, -16, -22, -11, -34, 11, -16, -48, -2, 53, 43, -47, -38, 12, 81, 56, 27, 29, 8, 76, 5, -37, -91, -41, 12, 4, -30, 116, -6, 7, -76, 9, 16, 21, -16, -3, 57, -37, -27, -26, -24, -46, -24, 19, -2, 25, 14, 45, 20, -32, -42, 38, -2, 4, 27, 42, 50, -16, 43, -76, 1, 18, 23, -4, 14, 12, -8, 27, -3, 70, -13, 8, 4, 22, -63, 98, -15, 9, -9, 71, -46, -12, 61, -47, 16, -22, -2, -35, 22, 4, -15, -3, -23, -23, 19, -7, -36, 26, 60, 12, 28, -8, -8, -19, 9, 5, -14, 19, -16, -20, -10, 16, -46, -5, -32, 21, 9, 69, -3, -1, 22, -6, 45, 12, -23, 13, -33, -14, 9, -25, 17, 0, -12, 2, 18, 17, -26, 35, 11, -49, -21, 12, -11, -24, 30, 16, -35, 1, 6, 24, -43, -21, -27, 3, 17, -19, 27, 22, 7, 7, 19, -55, 26, -9, -4, 1, -17, 10, -7, -30, 22, -18, -12, -3, 6, 22, -2, -42, -15, -1, -3, 0, -11, -3, 5, 27, -50, 1, -23, -4, -9, 0, -9, 19, -13, 10, 13, -11, -4, 12, 10, 9, 3, -44, -15, -1, -11, -1, 3, 10, -37, 2, 0, 17, -14, -22, -14, 17, -3, -15, 4, -16, 29, -24, 11, -5, 10, -13, -2, 2, 10, -19, -2, -19, 13, 13, -18, -39, 37, -15, -16, 2, 6, 2, 5, -21, -9, -23, 0, -11, -16, 10, -16, 12, 22, 16, 14, -6, 8, -1, -11, -17, 10, -10, 15, -13, 5, -26, 10, -30, 4, -40, -9, -1, -6, 21, -31, 5, -15, 35, -7, 21, 11, -5, 5, -3, -2, 0, 20, 3, -73, -33, -6, 10, 25, 19, -21, 29, 16, 4, 24, -36, 4, 17, 19, 21, 20, 24, -1, -22, -20, 10, -33, -22, -60, 33, -2, 63, -21, 10, -16, -43, 18, -3, -11, -28, -9, -16, -21, -11, 21, 24, 14, -6, 0, 25, -21, -25, -36, -3, -15, -11, -6, -10, 7, 20, -64, 14, 53, 16, -10, 12, 6, -69, -56, 2, 24, 0, 42, 22, -28, 18, 6, 25, -2, -16, 12, 3}

#define TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0 {-16, 105, -11, -31, -5, 16, 5, 79, -27, -8, 58, 20, 48, 66, 67, 37, 54, 36, 69, 64, 1, -5, -2, -8, 3, 0, 4, -5, -14, -3, 14, 91, -19, 37, 19, 50, 12, 87, 17, 28}

#define TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0_DEC_BITS {6}

#define LSTM_3_BIAS_LSHIFT {5}

#define LSTM_3_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0 {64, -65, -109, -35, -38, -18, 5, -23, 41, 1, 32, -35, 34, 37, 1, 16, -43, -24, -7, -30, 30, -50, 25, 52, -63, 5, 8, -40, 8, 22, 7, -24, 3, -17, 37, 54, 19, -26, -45, -33, 15, -2, 1, -17, -24, 19, -32, -31, -15, 6, -42, 17, 47, -64, -10, 28, 8, 13, -23, 29, 14, 8, 9, -27, -18, -29, 8, -21, 43, -60, 14, -7, 11, -19, -7, 10, -26, -3, -33, 50, 7, -23, -41, -22, 13, -11, 42, -30, 19, 14, 14, -4, 3, 6, 17, 24, -18, -30, -13, 44, 20, -98, 2, -18, 7, 18, -42, 29, -34, 4, -13, 16, 4, -12, -6, -34, 11, 34, -9, -10, -49, 4, 66, 26, 1, 28, 12, 20, -27, -48, -24, -1, 9, -39, -21, -1, 19, 3, 10, -14, 14, 0, 9, -10, 39, 13, -5, 29, 3, -18, -5, -19, -24, 35, -25, 6, -29, 13, -21, 22, -26, 3, 13, 56, -36, 26, -21, 45, 17, -6, -18, -39, 68, -99, -4, 6, -4, 34, 9, 13, -45, 59, 17, -36, 21, 32, -16, 16, 24, -55, -8, 16, -38, -28, -23, -35, 10, -12, -40, 22, 6, -12, -28, -5, 35, 3, -1, -22, 13, 14, 6, 13, -28, -5, -8, 45, 28, 8, -34, 35, 3, -103, 46, -33, 2, 14, 28, 27, -49, -16, 11, 11, 23, -21, 11, -9, 25, 65, -9, 24}

#define TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0 {14, -15, 39, 1, 18, -28, -12, 18, -34, -61, 78, 43, -14, 28, -17, 25, 12, -24, 9, -70, -27, 3, 41, 20, 31, 28, 4, 51, 7, -43, 7, 100, -67, -54, -2, 59, 9, -14, -22, 4, 1, -50, 10, -16, 6, 23, 5, 4, -29, -51, 68, 1, -10, -25, -2, 41, -15, 26, -19, -43, 24, 17, -53, 13, -43, -48, -8, -14, 71, -35, 18, -15, 9, -17, 45, 13, 4, 6, 20, 15, -21, -24, 20, -5, 37, -56, -24, -2, -4, -29, 21, -47, 21, -26, 20, -29, 26, 17, 25, 21, 41, -1, -31, 69, -12, 31, 30, 4, -21, -27, 27, -24, 21, 4, -17, -10, 38, 1, 34, 3, 16, -40, 15, 12, 64, -62, 15, 56, -16, 11, 7, 14, 15, -44, -34, 68, -9, -40, -29, -6, -12, -70, -20, -50}

#define TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0 {-11, -23, -29, -18, -30, -16, 97, 112, 88, 79, 112, 80, -8, 21, 10, -6, 9, 14, 26, 32, 1, 6, 30, 18}

#define TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0_DEC_BITS {6}

#define LSTM_4_BIAS_LSHIFT {6}

#define LSTM_4_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0 {15, -3, 6, -4, -14, 17, 12, -5, -11, -12, 25, 17, -7, 0, 17, -1, -6, -10, -28, 9, -37, 2, -2, 2, 15, -10, 18, 36, -12, 20, -5, 26, 7, 4, -12, -3, -1, 8, -17, -18, 10, -7, -20, 1, -25, 3, 13, -5, 11, -14, -9, -7, -6, -9, -3, -1, 1, -11, -1, 1, 16, 2, -8, 5, 0, -5, 21, -13, 9, 16, 3, -10, 31, -14, 29, 60, -27, 16, 34, 5, 7, -9, -6, 19, -6, -15, 6, -10, 16, -34, -43, -32, -73, -7, -13, -14}

#define TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0 {-3, 83, 93, 11, 33, 38, -23, -26, -8, 6, 22, 38, 28, 23, -26, 3, -35, -79, 24, -18, 17, -57, 11, 6, 27, 43, -15, -35, 5, 41, -10, -17, 24, 22, -18, -19, -14, 22, -14, 9, 20, 4, 29, 8, -22, 3, -15, 9, -38, -66, 56, -24, -22, 13, -38, 70, -36, -23, 34, -90, 74, -19, -121, 36}

#define TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0 {-17, -42, -28, -30, 55, 79, 27, 55, -7, -2, 5, -1, 34, 8, 12, 19}

#define TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0_DEC_BITS {5}

#define LSTM_5_BIAS_LSHIFT {6}

#define LSTM_5_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_1_KERNEL_0 {-25, -46, -95, -22, -61, -2, -5, 67, 96, 79, -49, 61, -48, 25, -26, -52, 91, 10, -75, 47, 4, -74, 35, -29}

#define TENSOR_DENSE_1_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_1_BIAS_0 {-113, 28, 2, -37, 38, -107}

#define TENSOR_DENSE_1_BIAS_0_DEC_BITS {9}

#define DENSE_1_BIAS_LSHIFT {3}

#define DENSE_1_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_3_INPUT_OUTPUT_DEC 7
#define LSTM_3_INPUT_OUTPUT_OFFSET 0
#define LSTM_3_OUTPUT_DEC 7
#define LSTM_3_OUTPUT_OFFSET 0
#define LSTM_4_OUTPUT_DEC 7
#define LSTM_4_OUTPUT_OFFSET 0
#define LSTM_5_OUTPUT_DEC 7
#define LSTM_5_OUTPUT_OFFSET 0
#define DENSE_1_OUTPUT_DEC 4
#define DENSE_1_OUTPUT_OFFSET 0
#define SOFTMAX_1_OUTPUT_DEC 7
#define SOFTMAX_1_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_3_input_config = {
    .super = {.name = "lstm_3_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_3_lstm_cell_3_kernel_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_kernel_0_dim[] = {3, 40};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_kernel_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_kernel_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dim[] = {10, 40};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_3_lstm_cell_3_bias_0_data[] = TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0;

const nnom_shape_data_t tensor_lstm_3_lstm_cell_3_bias_0_dim[] = {40};
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_bias_0_dec[] = TENSOR_LSTM_3_LSTM_CELL_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_3_lstm_cell_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_3_lstm_cell_3_bias_0 = {
    .p_data = (void*)tensor_lstm_3_lstm_cell_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_3_lstm_cell_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_3_lstm_cell_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_3_lstm_cell_config = {
    .super = {.name = "lstm_3"},
    .weights = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_3_lstm_cell_3_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 4,
    .units = 10
};

const nnom_rnn_config_t lstm_3_config = {
    .super = {.name = "lstm_3"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_4_lstm_cell_4_kernel_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_kernel_0_dim[] = {10, 24};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_kernel_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_kernel_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_4_lstm_cell_4_bias_0_data[] = TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0;

const nnom_shape_data_t tensor_lstm_4_lstm_cell_4_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_bias_0_dec[] = TENSOR_LSTM_4_LSTM_CELL_4_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_4_lstm_cell_4_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_4_lstm_cell_4_bias_0 = {
    .p_data = (void*)tensor_lstm_4_lstm_cell_4_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_4_lstm_cell_4_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_4_lstm_cell_4_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_4_lstm_cell_config = {
    .super = {.name = "lstm_4"},
    .weights = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_4_lstm_cell_4_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 1,
    .units = 6
};

const nnom_rnn_config_t lstm_4_config = {
    .super = {.name = "lstm_4"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_5_lstm_cell_5_kernel_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_kernel_0_dim[] = {6, 16};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_kernel_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_kernel_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dim[] = {4, 16};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_5_lstm_cell_5_bias_0_data[] = TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0;

const nnom_shape_data_t tensor_lstm_5_lstm_cell_5_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_bias_0_dec[] = TENSOR_LSTM_5_LSTM_CELL_5_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_5_lstm_cell_5_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_5_lstm_cell_5_bias_0 = {
    .p_data = (void*)tensor_lstm_5_lstm_cell_5_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_5_lstm_cell_5_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_5_lstm_cell_5_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_5_lstm_cell_config = {
    .super = {.name = "lstm_5"},
    .weights = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_5_lstm_cell_5_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 1,
    .units = 4
};

const nnom_rnn_config_t lstm_5_config = {
    .super = {.name = "lstm_5"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_1_kernel_0_data[] = TENSOR_DENSE_1_KERNEL_0;

const nnom_shape_data_t tensor_dense_1_kernel_0_dim[] = {4, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&lstm_3_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_3_lstm_cell_config), &lstm_3_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_4_lstm_cell_config), &lstm_4_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_5_lstm_cell_config), &lstm_5_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_1_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_1_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_20_NNOM_H