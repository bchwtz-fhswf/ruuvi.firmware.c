# Source files and includes common for all targets
RUUVI_PRJ_SOURCES= \
  $(PROJ_LIBS_DIR)/peak2peak/ruuvi_library_peak2peak.c \
  $(PROJ_LIBS_DIR)/ringbuffer/ruuvi_library_ringbuffer.c \
  $(PROJ_LIBS_DIR)/rms/ruuvi_library_rms.c \
  $(PROJ_LIBS_DIR)/variance/ruuvi_library_variance.c \
  $(PROJ_LIBS_DIR)/compress/ruuvi_library_compress.c

RUUVI_PRJ_INTEGRATION_TESTS_SOURCES= \
  $(PROJ_INTEGRATION_TESTS_DIR)/peak2peak/ruuvi_library_peak2peak.c \
  $(PROJ_INTEGRATION_TESTS_DIR)/ruuvi_library_test_analysis.c \
  $(PROJ_INTEGRATION_TESTS_DIR)/ruuvi_library_test.c \
  $(PROJ_INTEGRATION_TESTS_DIR)/ruuvi_library_compress_test.c 

RUUVI_LIB_SOURCES= \
  $(PROJ_LIBS_DIR)/compress/liblzf-3.6/lzf_c.c \
  $(PROJ_LIBS_DIR)/compress/liblzf-3.6/lzf_d.c

RUUVI_LIB_INCLUDES= \
  $(PROJ_LIBS_DIR)/compress \
  $(PROJ_LIBS_DIR)/compress/liblzf-3.6 

COMMON_SOURCES= \
  $(RUUVI_LIB_SOURCES) \
  $(RUUVI_PRJ_SOURCES) \
  $(RUUVI_PRJ_INTEGRATION_TESTS_SOURCES)

COMMON_INCLUDES= \
  $(PROJ_DIR) \
  $(PROJ_LIBS_DIR)/include \
  $(RUUVI_LIB_INCLUDES) \
  $(PROJ_INTEGRATION_TESTS_DIR)
