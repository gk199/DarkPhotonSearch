TString OR		   	= " || ";
TString AND 		= " && ";

TCut Cut_n_DiMuon = "n_dimuons >= 1";
TCut Cut_n_TruthDiMuon = "n_truthdimuons >= 1";
TCut Cut_fpga_trig = "fpga_trigger == 1";
TCut Cut_mass_res = "abs((dimuon_mass[0] - truthdimuon_mass[0]) / truthdimuon_mass[0]) < 0.1";