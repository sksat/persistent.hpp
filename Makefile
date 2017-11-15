KHPC_VERSION	= 003a
KHPC_DIR	= khpc$(KHPC_VERSION)
KHPC_ZIP	= $(KHPC_DIR).zip
KHPC_URL	= http://khfdpl.osask.jp/download/$(KHPC_ZIP)

$(KHPC_ZIP):
	wget $(KHPC_URL)

khpc: $(KHPC_ZIP)
	unzip $<
	mv $(KHPC_DIR) $@
