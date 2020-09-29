
DIP_DIR := ../__DIP__/

DIPObjects = DIP_Image.o DIP_Image_FileUtils.o DIP_Histogram.o DIP_MappingFunction.o DIP_Image_ProcessUtils.o \
             DIP_Neighbourhood.o DIP_Filter.o DIP_Filter_Mean.o DIP_Filter_OrderedStat.o DIP_Filter_WeightedSum.o \
             DIP_MathUtils.o DIP_Image_MathUtils.o DIP_AbstractImage.o DIP_RealImage.o DIP_Image_Utils.o \
             DIP_ComplexImage.o

ProcImgObjects = ProcImg_ApplyChangeBitsPerPixel.o ProcImg_ComputeHistogram.o ProcImg_ApplySpatialFilter.o \
             ProcImg_ComputeMappingFunction.o ProcImg_ApplyGreyLevelTrans.o ProcImg_ApplyHistogramEq.o \
             ProcImg_ApplyResizeImage.o ProcImg_ApplySharpenFilter.o ProcImg_ComputeFreqSpace.o \
             ProcImg_ApplyFreqFilter.o ProcImg_FFT_Test.o

ProcImgTargets = ProcImg_ApplyChangeBitsPerPixel ProcImg_ComputeHistogram ProcImg_ComputeMappingFunction \
             ProcImg_ApplySpatialFilter ProcImg_ApplyGreyLevelTrans ProcImg_ApplyHistogramEq \
             ProcImg_ApplyResizeImage ProcImg_ApplySharpenFilter ProcImg_ComputeFreqSpace \
             ProcImg_ApplyFreqFilter ProcImg_FFT_Test

LATEXSrc = LATEX_WriteHistogram.cpp LATEX_WriteMappingFunction.cpp

LATEXTargets = LATEX_WriteHistogram LATEX_WriteMappingFunction


all: $(ProcImgObjects) $(ProcImgTargets) $(LATEXTargets) 



%.o : %.cpp
	@echo 'Compiling... '$<
	@g++ -c -I$(DIP_DIR) $< -o $@

$(ProcImgTargets): % : %.o $(DIP_DIR)/DIP*.o
	@echo 'Building... '$@
	@g++ $@.o $(DIP_DIR)/*.o -o $@

$(LATEXTargets): % : $(LATEXSrc)
	@echo 'Building... '$@
	@g++ $@.cpp -o $@


.PHONY : clean
clean : 
	@echo 'Removing object files...'
	@rm *.o


