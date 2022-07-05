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
#define TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0 {17, -46, -61, 36, 71, 24, -34, 36, -45, -63, -29, -5, -8, -42, 11, -21, -63, 49, 52, -71, -78, 38, 39, 40, -28, -63, 28, -40, 9, 9, -30, 42, 21, -22, 22, 4, -27, 70, 1, -11, -49, -7, -9, 24, -4, 67, 33, 10, 2, 11, 23, 41, 16, -39, -32, -24, 40, -13, -80, -86, -29, 31, -9, 19, -31, -32, -14, -23, -48, 23, 6, 8, -4, 16, -22, -57, 59, 40, -59, 41, -3, 46, -43, 13, -6, -49, -21, -11, 8, 38, 34, -29, -57, 26, -58, 59, -51, -69, 62, -44, 5, -50, 55, -67, 35, 3, -4, -5, 45, 16, -15, 29, 36, -8, -22, 68, -17, -48, 1, 37, -44, -1, -27, 22, -40, -18, 13, -64, 58, -3, -13, 47, -18, -29, -7, -14, -2, -33, -25, -2, 2, -14, 39, -32}

#define TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0 {47, -71, 8, 22, 25, -37, -45, 86, 22, 12, 6, -46, -36, 104, 14, -7, -9, 9, 31, 28, -44, 55, -9, 54, 4, -3, 50, 60, -10, -16, -31, 52, -11, -43, -9, 16, 62, -6, -4, -68, -24, -60, -22, 36, 49, 26, -31, 44, 49, 16, 29, -4, 35, -24, -20, -27, -34, -30, -3, -2, 28, -20, -44, -33, 20, -25, -22, -27, 3, -4, -15, 38, -48, 21, 46, -18, 64, 21, -18, -66, -31, -20, 20, -16, -38, 41, -12, 20, 27, 3, -4, 0, 46, 82, -14, -36, 11, 5, 54, -5, -73, 35, -1, -1, 47, 0, -25, 28, 13, 3, -37, -67, -6, 1, -23, -6, -69, -8, -42, -63, -82, -6, 43, -22, -20, -48, -52, -23, -67, 21, 44, -66, -2, -41, 59, 54, -92, 43, 105, -86, -58, -73, 15, 83, 15, -15, 3, -17, 23, -4, -17, 35, 30, -35, -28, 43, 25, -7, 4, 27, 15, -18, 24, -21, -6, -1, -38, -30, -22, 16, 30, 19, 27, 26, 21, -3, -32, -6, -22, -13, 21, 2, -5, -26, -29, -32, -26, 3, 19, -32, -13, -27, 36, -23, 17, 26, -13, 27, 13, 27, -39, 32, -17, -57, 9, -40, 17, 30, -23, -71, -33, 17, -30, -37, 3, -42, -44, -50, -1, 22, 34, 1, -44, 21, 41, -11, 15, -7, 56, -27, -98, -47, 61, 26, -40, 45, 18, 6, 8, -17, 18, 22, -3, -40, 39, -19, 82, 9, -68, 44, -19, 15, -17, -38, -14, -38, -68, 36, 7, -3, -74, -51, -85, 14, -35, 12, -43, 7, -15, 9, -73, -6, 1, 2, -66, 5, -57, 1, -31, -1, 15, -15, 12, -28, 16, 57, 3, -11, -15, -12, 7, -13, -5, 13, -6, -2, -1, -14, -2, -4, -12, 17, -29, -11, 3, -13, -8, 4, -6, -17, 2, 27, 3, 15, 2, -14, -12, -9, -6, -7, -24, 3, 12, 6, -15, -2, 4, -2, -37, 28, 15, 31, 19, 11, 2, 2, 4, 40, -45, -4, 15, 4, -16, -17, 19, 7, 23, -7, 0, -30, -6, -25, 8, -5, 1, 15, -6, -4, 6, -6, 1, 5, 11, 16, -8, 11, -15, -3, -10, -14, -6, 15, 22, 19, -8, 5, 47, 9, -47, 34, 27, 35, -11, 1, 14, -27, 10, -10, 36, -1, -18, -16, 31, -7, 7, 29, 5, -5, -23, 25, -3, -1, -15, -13, 1, 9, 4, -28, -14, 10, 6, 9, -24, 5, -36, 5, -12, 28, 1, -14, 30, 20, 32, -16, -11, 0, 12, -6, -7, 3, 22, -33, 21, -35, -13, -27, 7, -82, -29, 85, 1, 39, -10, 3, 25, 108, 13, 28, 36, 4, -14, -72, 20, 56, -6, 34, 16, -21, 53, -3, -20, 11, 19, 19, -18, -5, 13, -14, -2, 20, 9, 61, -44, -26, -25, -31, -30, 14, -12, 17, 77, 17, 33, 4, 29, 4, -43, -19, 4, 7, 39, -21, 31, -11, -1, -3, -3, -7, -1, 21, -4, 10, 33, 41, -38, 67, -13, 53, 11, -14, -36, -24, -62, 29, -42, -29, -32, -10, -16, -118, 83, -15, -25, 24, 29, 50, -36, 16, -36, -4, -9, 34, -52, -39, -36, -40, -3, -17, -15, -22, 45, -44, 21, -17, 8, 24, -55, -18, -49, -39, -80, 2, -30, 20, 2, 10, -3, 3, -72, -91, 13, 48, -20, 22, -4, -24, 44, 16, 45, -52, 21, -14, 29, 79, -22, -20}

#define TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0 {-12, -4, -4, 27, -4, 11, -46, 8, 37, -19, 96, -11, 50, 55, 63, 48, 82, 35, 82, 12, 31, 50, 36, 55, -3, 8, -6, -4, 9, 1, -3, -12, -3, -15, 3, 10, 19, 25, 50, 56, 8, 51, 8, 12, 77, 30, 112, 1}

#define TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0_DEC_BITS {6}

#define LSTM_15_BIAS_LSHIFT {5}

#define LSTM_15_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0 {8, 15, -13, -8, -9, -2, 11, 25, -8, -15, -46, 55, -8, -7, -31, -28, -8, -1, 0, 0, 11, -31, 8, -2, -24, 27, -8, 17, -18, -5, -14, -5, 16, 3, 5, 2, 3, -13, 33, 1, 3, -66, -8, -33, -17, -8, -9, 7, -6, 11, -23, 34, -16, 2, 4, -7, -1, -18, 1, 25, -9, -3, 0, 3, -2, 11, 17, -33, -1, -2, -14, -3, 10, 7, -21, 22, 6, 23, -46, 2, 18, -42, 9, -10, -14, 40, -22, 8, 9, -25, -20, 24, 18, 0, -20, -11, -7, 3, 9, 15, -7, 13, -6, -11, -10, -6, 7, -17, 18, 2, -19, 16, -11, -9, -15, 7, -7, 18, 10, 23, -22, -6, -8, 5, -19, 15, 12, 3, -21, 14, -2, -13, -6, 8, 8, 12, 5, -5, -11, 25, 10, 0, -18, 1, 20, 27, -1, 6, -5, -1, -3, -13, -6, -17, -10, 16, -10, 6, 2, 8, -26, -22, -16, 2, -7, 2, -1, 8, 4, 7, -11, -30, -4, 15, -12, 7, -5, -4, -21, -11, -1, 5, 0, 6, 22, -1, 1, 7, 42, 7, 11, -15, 3, -3, -28, 6, -2, -12, 9, -7, 11, -8, 8, -21, -22, 16, -18, 13, 12, -5, 8, 1, -2, 1, -21, 7, 3, -9, 12, -6, -12, 6, -47, 4, 12, -4, 4, -26, -28, 30, -16, 28, 12, 16, -6, -3, 23, -21, 8, -34, 0, -5, 0, 10, -25, 14, -3, -15, -4, -7, -18, -15, 26, -1, -2, 28, -8, -12, -4, -24, 1, 6, 11, 8, -1, 8, -9, -13, -16, 1, -7, 18, -7, 3, -20, -17, -4, 5, 37, 28, 35, 12, 6, -6, -9, -20, -27, 2}

#define TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0 {8, 48, 21, 8, -72, -42, -100, -23, 41, 59, -17, 26, 62, 94, 58, -31, 24, 13, 8, -25, 18, 70, -58, -111, -29, -5, -16, 7, -7, 68, -2, 8, 7, 53, 22, -40, -65, -57, 60, -35, -35, -49, -4, 6, -4, -44, 52, 29, 43, -7, -36, -58, 10, -67, -25, -9, -62, -32, -12, 31, -52, -50, -3, 40, -34, -13, 92, -4, -28, 62, 35, 4, -24, -57, 33, -20, 29, 3, -23, 20, -3, -11, 46, 4, 19, -44, -12, 27, -34, 48, -7, -30, 13, 40, 26, -59, -24, -15, 22, 26, 10, -91, 7, -41, -4, -28, -31, 37, -15, -44, 50, -70, -10, 26, 12, 24, -47, 31, 79, -4, 82, 3, 4, -13, 9, -53, -83, -2, 14, -71, -4, 17, 2, -21, -63, -4, -51, 5, 22, 51, -12, 4, 1, 14}

#define TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0 {-3, -23, -24, -37, -3, -38, 30, 41, 68, 87, 33, 46, 1, 5, -12, 0, -12, 3, 12, 4, 8, 8, 4, 8}

#define TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0_DEC_BITS {5}

#define LSTM_16_BIAS_LSHIFT {6}

#define LSTM_16_OUTPUT_RSHIFT {4}

#define TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0 {18, -89, 9, -58, -15, -25, -14, -49, 18, -18, 11, -26, -18, 41, 26, 21, 30, 102, -11, -30, 56, 9, 9, 0, -13, -39, 32, 7, -27, 0, -48, -32, 53, 7, -39, -43, -37, -41, 38, -13, -17, -6, 7, -16, 45, 11, 16, -13, 15, 2, 3, -12, 25, -49, -37, -7, -38, 12, 7, 8, 22, -60, 3, 103, -31, -5, 50, -2, 24, 12, 10, -37, -75, 14, -42, 7, -27, -14, 28, -17, -5, 12, 6, 28, -3, -43, -45, 17, 13, 22, -21, -33, -5, -8, 38, 1, 3, 13, -47, -21, -30, -47, -41, -117, -16, -31, 3, -15, -36, -77, -17, -10, 35, -34, -7, 27, 32, 80, 31, -10, 18, 43, -27, 11, 34, -6, -45, -24, -36, 15, 41, 26, 26, -45, -62, 83, 0, -93, 81, -2, 30, 27, -8, -93}

#define TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0 {-2, 24, 36, 16, -40, 23, 23, -14, -17, -8, -31, 13, -3, 23, 4, 1, 33, 39, -11, 10, 81, 3, -31, 32, -10, -21, -7, -22, -11, 44, 1, 4, 16, 23, 13, 7, 51, -7, 35, 58, 3, 25, 15, -12, 41, -12, 7, -1, -23, 32, 0, 10, 58, 58, 57, 17, -3, 32, 11, 28, -59, 3, 25, 57, 4, -8, 9, 26, -7, -39, 10, -12, -1, -4, -2, -32, -7, -2, 1, 19, -6, 5, 12, -8, -14, 5, 6, -19, -50, -24, -11, -13, -1, -4, 13, 0, -15, 1, -1, 4, 6, 77, 13, 2, 11, 0, -8, 1, 47, -36, 21, 67, -12, 4, 7, -2, -11, -1, -26, 0, 6, -10, -16, 14, 11, 11, 74, 44, 11, -7, 46, 16, -53, 2, -1, 73, 48, -80, 31, 39, -17, 58, 10, -11}

#define TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0 {-38, -23, -36, -19, -39, -63, 60, 55, 57, 67, 42, 70, 5, -6, 1, 6, -11, 10, 5, 13, 20, 26, 17, 7}

#define TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0_DEC_BITS {5}

#define LSTM_17_BIAS_LSHIFT {7}

#define LSTM_17_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_5_KERNEL_0 {12, -32, -72, -9, 2, -58, -38, 46, 21, 77, -28, 27, -26, -20, 29, 35, 94, -26, 24, 53, -112, -44, 69, 21, -24, -32, -29, -123, -56, -32, 49, -77, 53, -11, 37, -9}

#define TENSOR_DENSE_5_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_5_BIAS_0 {48, 48, -36, -2, -94, -15}

#define TENSOR_DENSE_5_BIAS_0_DEC_BITS {7}

#define DENSE_5_BIAS_LSHIFT {5}

#define DENSE_5_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_15_INPUT_OUTPUT_DEC 7
#define LSTM_15_INPUT_OUTPUT_OFFSET 0
#define LSTM_15_OUTPUT_DEC 7
#define LSTM_15_OUTPUT_OFFSET 0
#define LSTM_16_OUTPUT_DEC 7
#define LSTM_16_OUTPUT_OFFSET 0
#define LSTM_17_OUTPUT_DEC 7
#define LSTM_17_OUTPUT_OFFSET 0
#define DENSE_5_OUTPUT_DEC 4
#define DENSE_5_OUTPUT_OFFSET 0
#define SOFTMAX_5_OUTPUT_DEC 7
#define SOFTMAX_5_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_15_input_config = {
    .super = {.name = "lstm_15_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_15_lstm_cell_15_kernel_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_kernel_0_dim[] = {3, 48};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_kernel_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_kernel_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dim[] = {12, 48};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_15_lstm_cell_15_bias_0_data[] = TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0;

const nnom_shape_data_t tensor_lstm_15_lstm_cell_15_bias_0_dim[] = {48};
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_bias_0_dec[] = TENSOR_LSTM_15_LSTM_CELL_15_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_15_lstm_cell_15_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_15_lstm_cell_15_bias_0 = {
    .p_data = (void*)tensor_lstm_15_lstm_cell_15_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_15_lstm_cell_15_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_15_lstm_cell_15_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_15_lstm_cell_config = {
    .super = {.name = "lstm_15"},
    .weights = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_15_lstm_cell_15_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 12
};

const nnom_rnn_config_t lstm_15_config = {
    .super = {.name = "lstm_15"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_16_lstm_cell_16_kernel_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_kernel_0_dim[] = {12, 24};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_kernel_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_kernel_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_16_lstm_cell_16_bias_0_data[] = TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0;

const nnom_shape_data_t tensor_lstm_16_lstm_cell_16_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_bias_0_dec[] = TENSOR_LSTM_16_LSTM_CELL_16_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_16_lstm_cell_16_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_16_lstm_cell_16_bias_0 = {
    .p_data = (void*)tensor_lstm_16_lstm_cell_16_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_16_lstm_cell_16_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_16_lstm_cell_16_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_16_lstm_cell_config = {
    .super = {.name = "lstm_16"},
    .weights = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_16_lstm_cell_16_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 6
};

const nnom_rnn_config_t lstm_16_config = {
    .super = {.name = "lstm_16"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_17_lstm_cell_17_kernel_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_kernel_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_kernel_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_17_lstm_cell_17_bias_0_data[] = TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0;

const nnom_shape_data_t tensor_lstm_17_lstm_cell_17_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_bias_0_dec[] = TENSOR_LSTM_17_LSTM_CELL_17_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_17_lstm_cell_17_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_17_lstm_cell_17_bias_0 = {
    .p_data = (void*)tensor_lstm_17_lstm_cell_17_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_17_lstm_cell_17_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_17_lstm_cell_17_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_17_lstm_cell_config = {
    .super = {.name = "lstm_17"},
    .weights = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_17_lstm_cell_17_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 2,
    .units = 6
};

const nnom_rnn_config_t lstm_17_config = {
    .super = {.name = "lstm_17"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_5_kernel_0_data[] = TENSOR_DENSE_5_KERNEL_0;

const nnom_shape_data_t tensor_dense_5_kernel_0_dim[] = {6, 6};
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
	nnom_layer_t* layer[7];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&lstm_15_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_15_lstm_cell_config), &lstm_15_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_16_lstm_cell_config), &lstm_16_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_17_lstm_cell_config), &lstm_17_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_5_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_5_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //HAR_GRU_NNOM_H