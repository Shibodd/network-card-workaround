# network-card-workaround
A workaround for https://www.reddit.com/r/MSI_Gaming/comments/f267gv/b450_mortar_max_no_ethernet_connection_at_startup/


Usage: card_restart.exe devcon_exe card_hwid
Return values:
1 if the connection works/started working
0 if the program failed to get the connection working
-1 if the program has invalid arguments (just checks the argcount)

Where devcon_exe is the path to the devcon executable, which comes with the Windows Driver Kit https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk,
and card_hwid is the card hardware id, which can be read in device manager > network adapters > your card properties > details > Hardware Ids or by using devcon. (Example: PCI\VEN_10EC&DEV_8168&CC_0200, but you actually only need PCI\VEN_10EC).

This workaround is supposed to be ran with high privileges at every login of any user, for example using the Windows built-in Task Scheduler.



Of course no license whatsoever, do what you want with this.
