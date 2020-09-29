
DIPObjects = DIP_Image_FileUtils.o DIP_Histogram.o DIP_MappingFunction.o DIP_Image_ProcessUtils.o \
             DIP_Neighbourhood.o DIP_Filter.o DIP_Filter_Mean.o DIP_Filter_OrderedStat.o DIP_Filter_WeightedSum.o \
             DIP_Math_Utils.o DIP_Image_MathUtils.o DIP_AbstractImage.o DIP_RealImage.o DIP_ComplexImage.o  \
             DIP_Image_Utils.o DIP_Image.o DIP_Image_MaskElement.o DIP_Image_Mask.o 


all: $(DIPObjects) 


%.o : %.cpp
	@echo 'Compiling... '$<
	@g++ -c $< -o $@


.PHONY : clean
clean : 
	@echo 'Removing object files...'
	@rm *.o


