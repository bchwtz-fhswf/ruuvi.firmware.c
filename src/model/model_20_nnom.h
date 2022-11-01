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
static const float highpass_coefficients[] = {0.2069928239055942f, -0.2069928239055942f, 0.0f, 0.2068179864931189f, -0.0f, 0.25f, -0.5f, 0.25f, 0.4490699651581907f, -0.2071676613180694f};
static const char* APP_ACTIVITY_RECOGNITION_CLASSES[] = {"jog","skip","stDown","stUp","stay","walk"};
#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_LSTM_21_LSTM_CELL_21_KERNEL_0 {-29, -2, 43, 7, 21, -10, 2, -1, -20, -23, 16, -53, 5, -43, 18, 22, 28, -47, 26, 29, 41, 21, -3, -14, -37, -22, 49, -29, -11, 29, -5, 6, 26, -4, 30, 19, 19, 5, 30, -12, -17, 26, -63, 6, 0, 38, -14, 10, -16, 24, -29, -65, 67, 20, 16, 42, 17, 10, -34, 1, 18, 33, 42, -53, -27, -22, 36, -34, -1, 17, -13, 2, 10, -47, 9, 23, 53, -57, 41, 55, 1, -7, 13, -26, 43, 30, -57, 65, -7, -25, 40, 18, -23, 3, 43, -13, 15, 31, 4, 24, -6, -59, -10, 7, -21, -4, 4, -10, 37, -60, 5, -14, -25, -3, 10, -33, 37, -11, 6, 24}

#define TENSOR_LSTM_21_LSTM_CELL_21_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_21_LSTM_CELL_21_RECURRENT_KERNEL_0 {-6, -35, 0, 37, 4, 1, -14, -18, -10, -17, 17, 30, 3, -6, 6, 3, 4, -42, 11, -16, 21, 7, -1, 17, -11, -20, -8, -29, -16, 11, -2, 14, 33, 15, -21, -14, 5, 7, -6, -12, 42, 2, 0, 4, -33, -13, 14, 29, -4, -21, -1, 1, -3, -18, 9, -14, -2, 0, 34, -5, -14, 6, 32, 6, 35, -14, 35, 0, -41, 0, -4, -25, 3, 9, 4, -8, 19, 34, -28, -6, -72, 30, 40, -6, 22, -22, 2, 3, -21, 6, -12, -12, 24, 3, 10, 3, -1, 25, -12, -23, 5, -35, 12, -17, -15, 32, -39, -1, 1, -7, -22, -19, 41, -20, -29, 25, -13, 16, 6, 18, 11, -3, -21, 10, -14, -11, 20, -14, -11, -11, -16, 1, -25, -4, 3, -8, 23, 9, 0, -15, -1, 15, -3, 10, 3, -18, 8, -6, -16, 1, -18, 18, -13, 16, -6, 10, 5, -15, 1, -8, 17, -18, 3, -12, -3, 12, -9, -5, 0, -8, -11, 16, -1, -10, 16, 25, 11, -18, -5, 9, 2, 0, -1, 9, 11, -12, -9, 9, 3, -7, 2, -1, -9, -1, -10, -15, -10, 3, -5, -4, -1, -1, 7, 2, -6, -2, 3, 5, 4, -1, 9, -7, 1, -13, 16, 1, -10, 10, -14, -6, 7, -11, 2, -8, 8, -1, -13, -12, -11, -2, 0, -9, -6, 18, -18, 10, -2, 9, 0, -9, -6, 6, -11, 1, -6, -1, 2, 5, 3, -1, 23, 9, -2, -4, 5, -1, -7, 6, -15, -4, 10, 2, 4, -6, -10, 6, 2, 7, -5, 9, 1, 3, -9, -9, -1, 1, -3, 7, -8, -5, 0, 4, -6, 5, 8, -3, -15, 7, 7, -5, -5, 3, 2, -16, 8, 16, 5, 0, 4, -2, 16, -36, -12, -8, 8, -2, -5, -5, 23, -21, 11, -12, -3, 5, 8, 1, -16, 2, -6, 32, 10, -6, -25, 1, 16, 6, 14, -7, -19, -20, 19, 11, -22, -12, 7, 4, 22, -15, 10, 24, -36, 24, 38, 14, -6, 7, 2, 15, 21, -9, 19, 15, -27, 19, -10, -11, 6, 2, -4, 0, 13, -5, -17, -15, -11, 8, 1, -15, -12, -11, 2, 10, -5, -5, 25, 6, 29, -6, 2, -1, -17, -3, -3, 14, -6, -13, -2, 12, -8, 8, -8, 1, 1, -7, -3, 7, -9, -18, -4, -11}

#define TENSOR_LSTM_21_LSTM_CELL_21_RECURRENT_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_21_LSTM_CELL_21_BIAS_0 {69, 67, 16, 49, 48, -12, -3, -7, -12, -18, 66, 42, 44, 53, 36, 23, 47, 50, 57, 41, -6, -7, -6, 0, 0, -1, -5, -4, 5, 6, 63, 80, 18, 51, 64, -3, 37, 9, 62, 20}

#define TENSOR_LSTM_21_LSTM_CELL_21_BIAS_0_DEC_BITS {6}

#define LSTM_21_BIAS_LSHIFT {7}

#define LSTM_21_OUTPUT_RSHIFT {6}

#define TENSOR_LSTM_22_LSTM_CELL_22_KERNEL_0 {44, -17, -65, -12, 1, 7, 21, 25, 21, 18, -16, -27, 10, -25, -11, 17, 49, -7, 49, 6, 79, -23, 2, 4, 19, 5, 30, -28, -9, 9, -12, 13, -59, 20, 10, 37, 42, 0, 24, 9, -8, 14, 12, 7, -3, -51, 35, 33, 31, -52, -38, -49, -1, -25, 18, -24, -3, -38, 8, -15, -28, -6, -9, -7, 32, 54, 12, 4, -26, -14, -30, -38, 29, -7, 37, 6, 47, 84, 20, 3, 53, 12, -26, 13, 10, -19, -26, 12, 11, -21, -19, -4, 17, -12, 6, 44, -28, -50, 49, 10, -28, -25, 30, -2, 51, 8, 35, -4, 44, -20, 47, 14, -37, -28, -5, 11, 2, -33, -44, -34, 26, -9, -33, 41, -22, -14, 26, -26, 17, 28, -25, -18, 1, -25, 40, -16, 14, -42, 23, -32, 3, 18, -3, 13, 9, -9, 13, -7, -25, -3, -1, -11, -41, 24, 2, 22, 21, -20, 2, -24, -13, -10, -4, 23, 3, -63, 30, 30, -8, 6, 19, -33, 5, -18, 47, 19, 33, -54, -23, -23, -2, -47, -23, -37, -2, -18, -18, -25, -11, -24, -25, -63, -4, 37, 8, 37, 41, 110, 17, 3, 13, 37, 30, -9, 64, -2, -2, 9, 25, -51, -5, 59, 31, -95, 24, 35, -12, -21, -11, 33, -53, -30, 21, 3, -2, 14, -18, 22, 42, 48, 24, 36, -4, -5, 6, -9, -16, -36, -49, -32}

#define TENSOR_LSTM_22_LSTM_CELL_22_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_22_LSTM_CELL_22_RECURRENT_KERNEL_0 {-13, -23, -16, 20, 14, -33, -66, 8, -8, 30, 16, 23, -26, 1, 42, 2, -16, 27, -45, -30, -1, -5, 12, -16, -23, -14, 5, 40, -2, -2, 25, 5, 5, 13, -17, 7, 26, 0, -8, 6, 9, 9, -4, 2, 19, 13, 2, -28, 35, -17, -52, 52, 17, -4, -50, 5, -30, -34, -7, -18, -21, -12, 0, -33, -8, -20, -36, 6, -30, 29, 4, 10, 9, -6, -1, -8, 6, -14, -18, 10, 6, 24, 10, -6, 9, 0, -1, 9, -1, 19, -6, 14, 7, -15, -5, -2, 16, 3, -4, -15, -24, -17, 5, 23, 2, -9, -9, 2, 3, -5, 47, 12, 11, -16, -6, -4, -20, 15, 24, 16, 6, -34, -1, 8, 14, -10, -21, 38, 21, -21, -51, 18, -22, 4, 0, 26, 38, -27, -26, -14, -50, 19, -5, -6}

#define TENSOR_LSTM_22_LSTM_CELL_22_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_22_LSTM_CELL_22_BIAS_0 {-33, 4, -28, -28, -49, 17, 99, 47, 101, 62, 98, 61, 12, -7, 1, 2, 11, -6, 20, -3, 19, -6, 7, 25}

#define TENSOR_LSTM_22_LSTM_CELL_22_BIAS_0_DEC_BITS {6}

#define LSTM_22_BIAS_LSHIFT {6}

#define LSTM_22_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_23_LSTM_CELL_23_KERNEL_0 {-11, -4, -3, 17, -9, -15, -21, 3, 8, -1, 3, -4, -44, 0, 30, 18, -21, 1, -1, 15, 7, -12, -28, -6, -9, 29, 6, -14, -13, 17, 9, 8, 14, 12, 1, 20, -23, 28, 26, 6, -35, -4, 3, -31, 5, -6, -13, -3, 4, 2, 1, 7, -3, 6, 5, -10, -2, -6, -7, -12, 18, 6, -1, -7, -11, -7, -10, 18, -3, 16, 13, 2, 2, 27, 11, 5, -17, 67, 2, -20, -7, 14, 32, 45, -40, -5, 3, 14, -41, -7, -12, -22, 3, -17, 0, -23}

#define TENSOR_LSTM_23_LSTM_CELL_23_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_23_LSTM_CELL_23_RECURRENT_KERNEL_0 {5, -24, -26, 13, 31, -9, -17, -3, -2, 25, 17, -13, 2, 28, -12, 18, -1, 8, -17, 17, -17, 31, 5, 14, 4, -18, 3, 16, -34, -15, 31, -2, -2, 2, 13, 1, -13, 18, 1, -7, 1, -2, -9, 3, 5, 5, -3, 12, 29, 29, -40, 11, -57, 26, 12, -15, -21, -34, -4, 35, -30, -94, 59, 54}

#define TENSOR_LSTM_23_LSTM_CELL_23_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_23_LSTM_CELL_23_BIAS_0 {-13, -44, -28, -31, 35, 55, 71, 66, -9, 3, 0, 0, 22, 20, 84, 38}

#define TENSOR_LSTM_23_LSTM_CELL_23_BIAS_0_DEC_BITS {5}

#define LSTM_23_BIAS_LSHIFT {6}

#define LSTM_23_OUTPUT_RSHIFT {4}

#define TENSOR_DENSE_7_KERNEL_0 {59, 31, 2, 30, -20, -19, -94, -26, -78, 73, -71, -78, 14, 63, 6, 87, -84, -20, 122, -82, -27, -64, -12, 72}

#define TENSOR_DENSE_7_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_7_BIAS_0 {-77, 79, 58, -117, -121, 61}

#define TENSOR_DENSE_7_BIAS_0_DEC_BITS {8}

#define DENSE_7_BIAS_LSHIFT {4}

#define DENSE_7_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_21_INPUT_OUTPUT_DEC 9
#define LSTM_21_INPUT_OUTPUT_OFFSET 0
#define LSTM_21_OUTPUT_DEC 7
#define LSTM_21_OUTPUT_OFFSET 0
#define LSTM_22_OUTPUT_DEC 7
#define LSTM_22_OUTPUT_OFFSET 0
#define LSTM_23_OUTPUT_DEC 7
#define LSTM_23_OUTPUT_OFFSET 0
#define DENSE_7_OUTPUT_DEC 4
#define DENSE_7_OUTPUT_OFFSET 0
#define SOFTMAX_7_OUTPUT_DEC 7
#define SOFTMAX_7_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_21_input_config = {
    .super = {.name = "lstm_21_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_21_lstm_cell_21_kernel_0_data[] = TENSOR_LSTM_21_LSTM_CELL_21_KERNEL_0;

const nnom_shape_data_t tensor_lstm_21_lstm_cell_21_kernel_0_dim[] = {3, 40};
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_kernel_0_dec[] = TENSOR_LSTM_21_LSTM_CELL_21_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_21_lstm_cell_21_kernel_0 = {
    .p_data = (void*)tensor_lstm_21_lstm_cell_21_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_21_lstm_cell_21_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_data[] = TENSOR_LSTM_21_LSTM_CELL_21_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_dim[] = {10, 40};
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_dec[] = TENSOR_LSTM_21_LSTM_CELL_21_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_21_lstm_cell_21_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_21_lstm_cell_21_bias_0_data[] = TENSOR_LSTM_21_LSTM_CELL_21_BIAS_0;

const nnom_shape_data_t tensor_lstm_21_lstm_cell_21_bias_0_dim[] = {40};
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_bias_0_dec[] = TENSOR_LSTM_21_LSTM_CELL_21_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_21_lstm_cell_21_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_21_lstm_cell_21_bias_0 = {
    .p_data = (void*)tensor_lstm_21_lstm_cell_21_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_21_lstm_cell_21_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_21_lstm_cell_21_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_21_lstm_cell_config = {
    .super = {.name = "lstm_21"},
    .weights = (nnom_tensor_t*)&tensor_lstm_21_lstm_cell_21_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_21_lstm_cell_21_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_21_lstm_cell_21_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 5,
    .units = 10
};

const nnom_rnn_config_t lstm_21_config = {
    .super = {.name = "lstm_21"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_22_lstm_cell_22_kernel_0_data[] = TENSOR_LSTM_22_LSTM_CELL_22_KERNEL_0;

const nnom_shape_data_t tensor_lstm_22_lstm_cell_22_kernel_0_dim[] = {10, 24};
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_kernel_0_dec[] = TENSOR_LSTM_22_LSTM_CELL_22_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_22_lstm_cell_22_kernel_0 = {
    .p_data = (void*)tensor_lstm_22_lstm_cell_22_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_22_lstm_cell_22_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_data[] = TENSOR_LSTM_22_LSTM_CELL_22_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_dec[] = TENSOR_LSTM_22_LSTM_CELL_22_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_22_lstm_cell_22_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_22_lstm_cell_22_bias_0_data[] = TENSOR_LSTM_22_LSTM_CELL_22_BIAS_0;

const nnom_shape_data_t tensor_lstm_22_lstm_cell_22_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_bias_0_dec[] = TENSOR_LSTM_22_LSTM_CELL_22_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_22_lstm_cell_22_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_22_lstm_cell_22_bias_0 = {
    .p_data = (void*)tensor_lstm_22_lstm_cell_22_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_22_lstm_cell_22_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_22_lstm_cell_22_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_22_lstm_cell_config = {
    .super = {.name = "lstm_22"},
    .weights = (nnom_tensor_t*)&tensor_lstm_22_lstm_cell_22_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_22_lstm_cell_22_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_22_lstm_cell_22_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 3,
    .units = 6
};

const nnom_rnn_config_t lstm_22_config = {
    .super = {.name = "lstm_22"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_23_lstm_cell_23_kernel_0_data[] = TENSOR_LSTM_23_LSTM_CELL_23_KERNEL_0;

const nnom_shape_data_t tensor_lstm_23_lstm_cell_23_kernel_0_dim[] = {6, 16};
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_kernel_0_dec[] = TENSOR_LSTM_23_LSTM_CELL_23_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_23_lstm_cell_23_kernel_0 = {
    .p_data = (void*)tensor_lstm_23_lstm_cell_23_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_23_lstm_cell_23_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_data[] = TENSOR_LSTM_23_LSTM_CELL_23_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_dim[] = {4, 16};
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_dec[] = TENSOR_LSTM_23_LSTM_CELL_23_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_23_lstm_cell_23_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_23_lstm_cell_23_bias_0_data[] = TENSOR_LSTM_23_LSTM_CELL_23_BIAS_0;

const nnom_shape_data_t tensor_lstm_23_lstm_cell_23_bias_0_dim[] = {16};
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_bias_0_dec[] = TENSOR_LSTM_23_LSTM_CELL_23_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_23_lstm_cell_23_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_23_lstm_cell_23_bias_0 = {
    .p_data = (void*)tensor_lstm_23_lstm_cell_23_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_23_lstm_cell_23_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_23_lstm_cell_23_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_23_lstm_cell_config = {
    .super = {.name = "lstm_23"},
    .weights = (nnom_tensor_t*)&tensor_lstm_23_lstm_cell_23_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_23_lstm_cell_23_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_23_lstm_cell_23_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 1,
    .units = 4
};

const nnom_rnn_config_t lstm_23_config = {
    .super = {.name = "lstm_23"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_7_kernel_0_data[] = TENSOR_DENSE_7_KERNEL_0;

const nnom_shape_data_t tensor_dense_7_kernel_0_dim[] = {4, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&lstm_21_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_21_lstm_cell_config), &lstm_21_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_22_lstm_cell_config), &lstm_22_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_23_lstm_cell_config), &lstm_23_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_7_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_7_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_20_NNOM_H