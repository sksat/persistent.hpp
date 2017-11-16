KHPC_VERSION	= 003a
KHPC_DIR	= khpc$(KHPC_VERSION)
KHPC_ZIP	= $(KHPC_DIR).zip
KHPC_URL	= http://khfdpl.osask.jp/download/$(KHPC_ZIP)

TARGET		= test.out

%.o : %.c
	gcc -c $< -o $@

%.o : %.cc
	g++ -std=c++11 -c $< -o $@

$(TARGET): main.o khpc/khpc0.o
	g++ $^ -o $@

run: $(TARGET)
	./$<

clean:
	rm -rf $(TARGET)
	rm -rf *.o
	rm -rf khpc/*.o

$(KHPC_ZIP):
	wget $(KHPC_URL)

khpc: $(KHPC_ZIP)
	unzip $<
	mv $(KHPC_DIR) $@

pbdtol: khpc
	gcc $</$@.c -o $@
