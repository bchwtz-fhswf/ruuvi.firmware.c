#ifndef MODEL_9_NNOM_H
#define MODEL_9_NNOM_H

#define APP_ACTIVITY_MODEL_NAME model_9_nnom
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
#define TENSOR_LSTM_9_LSTM_CELL_9_KERNEL_0 {3, 25, -9, 49, 39, -29, 29, -18, -3, 10, -16, -8, -18, 29, -8, -19, -19, -35, 41, 39, -46, 0, 28, -23, -40, -7, -42, 50, 51, 45, 2, -35, 58, 65, 43, -51, -21, -75, 20, -16, -16, 32, -25, 8, 9, 3, -34, 28, 44, 36, 79, 36, 20, -17, -77, -10, -16, -10, -7, 7, 12, -24, 16, 1, -8, 4, 8, 29, -32, 1, -26, 45, 25, 37, 20, 54, -33, 67, -33, 74, 8, -17, -4, 9, -5, -5, -21, 24, 47, -68, -71, 47, 2, 4, 2, -23, -41, 43, -70, -60, -64, 1, -7, -54, 43, -27, -11, 1, 14, 18, -31, 63, 54, -18, 37, 0, 7, -9, -25, 20, 4, 42, -5, 18, -10, -46, 7, 47, -58, -19, 5, 11, 8, -41, -29, 64, 65, 6, -45, -45, -7, 61, 30, 42}

#define TENSOR_LSTM_9_LSTM_CELL_9_KERNEL_0_DEC_BITS {4}

#define TENSOR_LSTM_9_LSTM_CELL_9_RECURRENT_KERNEL_0 {-10, -33, 36, -44, -9, 25, -12, 29, -37, 29, -63, -88, 21, -82, -42, 86, -8, 42, -37, -31, -9, 25, 27, -38, 21, 37, -7, -77, -18, 0, -9, -23, 20, 1, 7, 45, 17, -63, 16, -18, 1, 22, 27, 27, 35, -46, 22, -72, -12, 24, -16, -6, 28, -17, -80, 23, 35, 11, -31, -40, 21, -3, -1, 6, -24, -52, -16, 15, 29, -19, -32, -4, 30, -24, 35, 11, 65, 23, -114, 17, 43, 31, -2, 16, 13, -55, 88, 49, -1, 19, -23, 0, 0, -18, 54, -39, -25, -13, -4, -53, -18, 29, -48, 48, 16, 2, 22, -22, 21, -13, -86, 76, 7, 37, 9, -7, 48, -104, -15, -39, -56, 47, -16, -32, -17, -79, 43, 4, -20, -39, -25, 10, 46, 27, -16, -66, -23, 2, -35, -40, 57, -32, -10, -36, -5, 23, -51, 19, -31, -28, -39, -11, 13, 17, -55, 87, 16, -37, -13, 4, -25, 33, 9, -14, -16, 18, -30, -21, -9, -22, -30, -45, 32, 7, -14, 31, 19, -74, 34, -9, -32, -10, 26, -10, -5, 21, 38, -38, 32, -8, 5, -7, -26, 44, -39, -2, 3, -6, -4, -38, -22, 16, -63, -24, 14, 48, -41, -14, 36, 3, 7, -12, -5, -2, -15, -9, 52, -9, -6, 18, -1, -47, -22, 35, -8, 6, -12, -16, 29, -10, 29, -4, -55, -17, 20, 23, -4, 24, 44, -32, -8, 45, -4, -4, 41, -34, 14, -36, -4, 1, -21, 62, 3, 22, 11, -24, 23, -6, 14, -34, 6, 31, 13, -14, -8, -19, -26, -32, -3, 43, 6, -32, 21, -67, -25, -6, -14, -31, -6, 26, 4, -43, -3, -27, -29, 36, -14, 2, 10, 1, 11, -5, 31, 16, -27, 0, -16, 8, -4, -11, 2, 5, -7, -13, 18, 11, 28, -3, -2, -6, -5, -7, -21, 18, -4, -29, 17, 15, 7, 3, -4, 14, -10, 13, 0, 6, 13, 10, 2, -11, -12, 10, 20, 14, 19, 1, -29, -25, -11, -7, 7, 1, 9, 18, 27, -13, 5, -15, -4, -7, 5, 14, -8, 9, -23, -6, 13, -6, -7, 7, 7, 29, 39, 3, -6, 6, 5, 5, 9, 15, -16, -1, -6, -3, -14, 27, 28, -3, -11, 3, 4, -1, -15, 5, 6, 2, 4, 11, -7, 5, 2, 22, -10, -27, -6, 17, -30, -34, 6, 16, -1, 5, -21, -3, 2, 14, 18, 4, -8, 15, -3, -25, 17, -3, -20, 8, 12, 2, -20, 6, 9, -20, 6, -14, 0, -29, 9, 1, -19, -3, 9, -5, 0, -6, 17, 39, -6, 24, -7, 4, -22, -9, -29, 17, 26, -81, -57, 12, -3, -10, 0, -2, -4, 18, -6, -63, -5, -47, 21, -36, -26, 10, 16, 22, 26, -36, 7, -12, 40, -26, 1, 36, -3, 27, -4, -63, 27, -57, 18, -20, -8, 24, -34, 40, 17, 2, 6, -10, 21, 1, -44, -19, 18, 22, -36, -19, 36, -13, -13, -14, -17, -16, 5, -35, 50, -10, 4, -21, -18, -76, 9, 11, 15, 62, 20, -10, 50, -29, 23, 22, -76, -31, 17, 27, 33, -24, 44, -20, 14, -27, -13, -32, 6, 36, -7, 14, -6, -8, -39, 16, -25, -9, 28, 4, 26, 8, -10, 44, 20, -36, 13, -52, 57, -12, -62, -25, 4, -16, -4, -32, 28, -30, 18, 17, -43, 14, 32, -4, 3, 37, 76, -15, -44, -43, -66, 17}

#define TENSOR_LSTM_9_LSTM_CELL_9_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_9_LSTM_CELL_9_BIAS_0 {25, -42, 73, -7, -16, 16, -35, 36, -22, 1, -31, 20, 71, 42, 35, 64, 54, 57, 65, 22, 108, 56, 91, 59, -2, -5, 1, 5, -6, 7, 2, -9, -4, 3, 7, -4, 82, 26, 83, 61, 23, 16, 56, 43, 12, 22, 14, 88}

#define TENSOR_LSTM_9_LSTM_CELL_9_BIAS_0_DEC_BITS {6}

#define LSTM_9_BIAS_LSHIFT {7}

#define LSTM_9_OUTPUT_RSHIFT {6}

#define TENSOR_LSTM_10_LSTM_CELL_10_KERNEL_0 {-1, 23, -10, 7, 5, 36, 2, 52, 43, 8, -1, 12, -7, -43, 5, -17, -3, -28, -38, -48, -5, 19, 48, -6, 19, -1, -17, -34, -18, -17, 21, -6, -9, -23, 12, 52, -8, -16, -11, -14, 45, -32, 14, -100, -17, -49, 11, -7, -5, -1, 10, -31, 22, -30, 12, -5, 42, -32, 13, -5, 18, -15, -23, -18, 35, -3, 31, -42, -32, -25, -36, 9, 56, 2, 23, -5, -29, -17, -46, -16, 31, 2, -8, 48, -9, -7, 10, 27, 18, -19, -21, -13, -5, 14, 14, 31, 11, 3, -4, 5, -13, 12, 22, -13, 13, 1, -7, -56, -23, 14, -33, -29, -4, 6, 45, 33, -11, 9, -22, -35, 42, 16, -10, 15, 2, -17, -4, -37, -6, 32, 14, 13, 4, 1, -70, 68, -26, -37, 7, 59, 13, -12, -32, -33, 17, -1, -15, -45, -13, 11, -7, 33, 10, -3, -33, 49, 29, -16, -4, 33, 34, -8, 1, 20, 3, 17, -16, -15, 31, 45, -11, -4, 7, -15, -21, 15, -4, -18, -31, 10, -28, 4, 26, -17, -23, 36, 22, -16, 37, -22, -4, 33, -15, -21, -7, -17, 10, 21, -20, -6, 45, -5, 37, 33, -11, 40, -25, -24, 40, 23, 10, -6, -9, -71, -37, -28, 32, 31, 12, -5, -36, -64, -54, -41, -28, -7, 12, -2, -15, -22, 19, 39, 53, 10, 22, -12, -17, -21, -26, -10, 6, 9, -13, 41, -38, 6, 22, -21, 12, 16, 32, -10, 8, -19, -19, -35, 6, 8, 51, 36, -1, -37, -88, -38, 19, 14, 3, 15, 6, -27, -50, -42, -5, 1, -4, -29, 8, -12, -6, -9, 16, -9, 3, 37, -4, -58, -45, -8}

#define TENSOR_LSTM_10_LSTM_CELL_10_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_10_LSTM_CELL_10_RECURRENT_KERNEL_0 {0, -70, 43, 29, 26, -7, -14, -35, 21, 12, 8, -18, 26, -6, -14, -34, 49, 26, 42, 1, 55, -13, -20, -55, 69, -23, 56, -13, 28, -40, -28, 14, 6, -32, 44, -12, -17, 32, 29, -60, 24, -62, 20, -33, 35, 25, -6, -65, 20, 23, -37, -14, -33, -40, -45, 55, 26, 17, 33, 23, 33, 80, -48, -67, 5, -5, -25, 3, 22, 41, -81, 32, 32, 2, 1, -18, -16, 18, -23, -60, 2, -3, -22, 22, 18, -21, -16, 1, -2, -30, 54, -14, -5, 7, -2, -7, 2, -2, 31, 1, -32, -66, -12, 40, 5, -28, 4, 39, -26, 63, 12, -76, 9, 18, 4, 14, 32, 31, 7, -72, 10, -32, 19, 18, -46, -38, -24, 25, -2, 38, 19, 3, 39, 13, -54, -8, 39, -36, -11, -14, 0, 0, -53, 21}

#define TENSOR_LSTM_10_LSTM_CELL_10_RECURRENT_KERNEL_0_DEC_BITS {6}

#define TENSOR_LSTM_10_LSTM_CELL_10_BIAS_0 {11, 0, 19, -13, -36, -47, 91, 74, 94, 70, 64, 92, -27, 12, 29, -19, -9, 12, 9, 7, 22, 18, -3, 29}

#define TENSOR_LSTM_10_LSTM_CELL_10_BIAS_0_DEC_BITS {6}

#define LSTM_10_BIAS_LSHIFT {6}

#define LSTM_10_OUTPUT_RSHIFT {5}

#define TENSOR_LSTM_11_LSTM_CELL_11_KERNEL_0 {8, 20, -21, -33, 14, 0, -14, -81, -28, -28, 31, 30, -32, -27, -22, 22, 6, -2, 16, 11, 17, -15, -15, 16, -4, 23, -11, 30, -31, -33, -4, 19, -25, -8, 24, 1, 25, 6, -6, -15, -5, 26, 8, -2, 19, -12, 1, -11, -28, -51, 5, -7, -56, -7, 5, -53, -1, 26, -4, -12, 36, -15, 21, -1, -5, 20, -58, -22, 12, -32, -12, -27, -5, -12, -37, 53, 1, 1, -27, 45, 17, 6, -18, -27, -65, 15, 17, -46, -6, -14, -32, 3, -18, 27, -17, 20, 6, 8, -32, 14, -31, -24, 9, -22, 3, 9, -8, 8, 70, 12, -11, -20, 7, 33, -3, 24, 15, -12, -3, -65, 0, -36, -27, -17, -29, -49, 31, -2, -23, 1, 29, -12, 28, 33, 39, 2, -7, 5, -98, -25, 0, -37, 5, -20}

#define TENSOR_LSTM_11_LSTM_CELL_11_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_11_LSTM_CELL_11_RECURRENT_KERNEL_0 {16, -9, -32, 18, 2, -4, 14, -10, 11, 10, -9, 22, 13, 37, 22, 16, 1, -35, -21, -9, -33, -26, -4, 6, 1, -13, -35, 17, 1, 6, -6, -11, 14, 23, -14, 4, 13, 11, -5, -4, -12, -12, -11, -20, 23, 32, 52, -3, 14, 20, 2, -4, 6, 35, 18, 9, 8, -9, -37, 3, -31, 8, 1, -8, 45, 36, -10, -1, 29, 19, 23, 6, -13, -9, 3, -4, -12, 9, 4, 11, 6, -8, 8, -15, -10, -12, 4, -12, 4, 7, -3, 16, -7, -2, 1, 3, -3, -6, -7, 1, -18, 43, 22, 47, 1, -7, -5, -15, -28, 20, 16, -21, 10, 24, -2, -7, 9, 10, 39, 12, 11, 24, -26, -7, -9, 16, -21, 54, 32, -12, -45, -10, 5, -21, 4, 1, 66, 30, 11, 7, 12, 23, 37, -9}

#define TENSOR_LSTM_11_LSTM_CELL_11_RECURRENT_KERNEL_0_DEC_BITS {5}

#define TENSOR_LSTM_11_LSTM_CELL_11_BIAS_0 {-34, -29, -34, -29, -32, -9, 66, 68, 55, 56, 64, 38, -3, -2, -6, 1, 9, 2, 11, 19, 16, 22, 28, 26}

#define TENSOR_LSTM_11_LSTM_CELL_11_BIAS_0_DEC_BITS {5}

#define LSTM_11_BIAS_LSHIFT {7}

#define LSTM_11_OUTPUT_RSHIFT {5}

#define TENSOR_DENSE_3_KERNEL_0 {-8, -51, 92, 86, 15, 43, -59, -15, -45, 13, -52, -30, -3, -6, -58, 43, 14, 30, 14, 15, -43, 62, 16, 7, -71, -41, 30, -16, -93, -17, 4, 65, -9, 7, 6, -94}

#define TENSOR_DENSE_3_KERNEL_0_DEC_BITS {5}

#define TENSOR_DENSE_3_BIAS_0 {-44, -60, -57, -37, 25, 93}

#define TENSOR_DENSE_3_BIAS_0_DEC_BITS {8}

#define DENSE_3_BIAS_LSHIFT {4}

#define DENSE_3_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define LSTM_9_INPUT_OUTPUT_DEC 9
#define LSTM_9_INPUT_OUTPUT_OFFSET 0
#define LSTM_9_OUTPUT_DEC 7
#define LSTM_9_OUTPUT_OFFSET 0
#define LSTM_10_OUTPUT_DEC 7
#define LSTM_10_OUTPUT_OFFSET 0
#define LSTM_11_OUTPUT_DEC 7
#define LSTM_11_OUTPUT_OFFSET 0
#define DENSE_3_OUTPUT_DEC 4
#define DENSE_3_OUTPUT_OFFSET 0
#define SOFTMAX_3_OUTPUT_DEC 7
#define SOFTMAX_3_OUTPUT_OFFSET 0

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

const nnom_io_config_t lstm_9_input_config = {
    .super = {.name = "lstm_9_input"},
    .tensor = (nnom_tensor_t*)&tensor_Placeholder_0
};
const int8_t tensor_lstm_9_lstm_cell_9_kernel_0_data[] = TENSOR_LSTM_9_LSTM_CELL_9_KERNEL_0;

const nnom_shape_data_t tensor_lstm_9_lstm_cell_9_kernel_0_dim[] = {3, 48};
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_kernel_0_dec[] = TENSOR_LSTM_9_LSTM_CELL_9_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_9_lstm_cell_9_kernel_0 = {
    .p_data = (void*)tensor_lstm_9_lstm_cell_9_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_9_lstm_cell_9_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_data[] = TENSOR_LSTM_9_LSTM_CELL_9_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_dim[] = {12, 48};
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_dec[] = TENSOR_LSTM_9_LSTM_CELL_9_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_9_lstm_cell_9_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_9_lstm_cell_9_bias_0_data[] = TENSOR_LSTM_9_LSTM_CELL_9_BIAS_0;

const nnom_shape_data_t tensor_lstm_9_lstm_cell_9_bias_0_dim[] = {48};
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_bias_0_dec[] = TENSOR_LSTM_9_LSTM_CELL_9_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_9_lstm_cell_9_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_9_lstm_cell_9_bias_0 = {
    .p_data = (void*)tensor_lstm_9_lstm_cell_9_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_9_lstm_cell_9_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_9_lstm_cell_9_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_9_lstm_cell_config = {
    .super = {.name = "lstm_9"},
    .weights = (nnom_tensor_t*)&tensor_lstm_9_lstm_cell_9_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_9_lstm_cell_9_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_9_lstm_cell_9_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 4,
    .units = 12
};

const nnom_rnn_config_t lstm_9_config = {
    .super = {.name = "lstm_9"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_10_lstm_cell_10_kernel_0_data[] = TENSOR_LSTM_10_LSTM_CELL_10_KERNEL_0;

const nnom_shape_data_t tensor_lstm_10_lstm_cell_10_kernel_0_dim[] = {12, 24};
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_kernel_0_dec[] = TENSOR_LSTM_10_LSTM_CELL_10_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_10_lstm_cell_10_kernel_0 = {
    .p_data = (void*)tensor_lstm_10_lstm_cell_10_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_10_lstm_cell_10_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_data[] = TENSOR_LSTM_10_LSTM_CELL_10_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_dec[] = TENSOR_LSTM_10_LSTM_CELL_10_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_10_lstm_cell_10_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_10_lstm_cell_10_bias_0_data[] = TENSOR_LSTM_10_LSTM_CELL_10_BIAS_0;

const nnom_shape_data_t tensor_lstm_10_lstm_cell_10_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_bias_0_dec[] = TENSOR_LSTM_10_LSTM_CELL_10_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_10_lstm_cell_10_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_10_lstm_cell_10_bias_0 = {
    .p_data = (void*)tensor_lstm_10_lstm_cell_10_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_10_lstm_cell_10_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_10_lstm_cell_10_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_10_lstm_cell_config = {
    .super = {.name = "lstm_10"},
    .weights = (nnom_tensor_t*)&tensor_lstm_10_lstm_cell_10_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_10_lstm_cell_10_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_10_lstm_cell_10_bias_0,
    .q_dec_z = 4,
    .q_dec_h = 7,
    .q_dec_c = 3,
    .units = 6
};

const nnom_rnn_config_t lstm_10_config = {
    .super = {.name = "lstm_10"},
    .return_sequence = true,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_lstm_11_lstm_cell_11_kernel_0_data[] = TENSOR_LSTM_11_LSTM_CELL_11_KERNEL_0;

const nnom_shape_data_t tensor_lstm_11_lstm_cell_11_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_kernel_0_dec[] = TENSOR_LSTM_11_LSTM_CELL_11_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_11_lstm_cell_11_kernel_0 = {
    .p_data = (void*)tensor_lstm_11_lstm_cell_11_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_11_lstm_cell_11_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_data[] = TENSOR_LSTM_11_LSTM_CELL_11_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_dim[] = {6, 24};
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_dec[] = TENSOR_LSTM_11_LSTM_CELL_11_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_11_lstm_cell_11_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_11_lstm_cell_11_bias_0_data[] = TENSOR_LSTM_11_LSTM_CELL_11_BIAS_0;

const nnom_shape_data_t tensor_lstm_11_lstm_cell_11_bias_0_dim[] = {24};
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_bias_0_dec[] = TENSOR_LSTM_11_LSTM_CELL_11_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_11_lstm_cell_11_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_11_lstm_cell_11_bias_0 = {
    .p_data = (void*)tensor_lstm_11_lstm_cell_11_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_11_lstm_cell_11_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_11_lstm_cell_11_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_11_lstm_cell_config = {
    .super = {.name = "lstm_11"},
    .weights = (nnom_tensor_t*)&tensor_lstm_11_lstm_cell_11_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_11_lstm_cell_11_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_11_lstm_cell_11_bias_0,
    .q_dec_z = 3,
    .q_dec_h = 7,
    .q_dec_c = 1,
    .units = 6
};

const nnom_rnn_config_t lstm_11_config = {
    .super = {.name = "lstm_11"},
    .return_sequence = false,
    .stateful = false,
    .go_backwards = false
};
const int8_t tensor_dense_3_kernel_0_data[] = TENSOR_DENSE_3_KERNEL_0;

const nnom_shape_data_t tensor_dense_3_kernel_0_dim[] = {6, 6};
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

	layer[0] = input_s(&lstm_9_input_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_9_lstm_cell_config), &lstm_9_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_10_lstm_cell_config), &lstm_10_config), layer[1]);
	layer[3] = model.hook(rnn_s(lstm_cell_s(&lstm_11_lstm_cell_config), &lstm_11_config), layer[2]);
	layer[4] = model.hook(dense_s(&dense_3_config), layer[3]);
	layer[5] = model.hook(softmax_s(&softmax_3_config), layer[4]);
	layer[6] = model.hook(output_s(&output0_config), layer[5]);
	*state = model_compile(&model, layer[0], layer[6]);
	return &model;
}
#endif // INCLUDE_MODEL

#endif //MODEL_9_NNOM_H