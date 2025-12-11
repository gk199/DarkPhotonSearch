TString OR		   	= " || ";
TString AND 		= " && ";

TCut Cut_n_DiMuon = "n_dimuons >= 1";
TCut Cut_n_TruthDiMuon = "n_truthdimuons >= 1";
TCut Cut_fpga_trig = "fpga_trigger == 1";
TCut Cut_mass_res = "abs((dimuon_mass[0] - truthdimuon_mass[0]) / truthdimuon_mass[0]) < 0.1";

TCut Cut_dimuon_pos = "dimuon_npos_z[0] > 250 && dimuon_ppos_z[0] > 250";
TCut Cut_nTracks = "n_tracks >= 2";
TCut Cut_dimuon_pT_p = "dimuon_pmom_z[0] < 30";
TCut Cut_dimuon_pT_n = "dimuon_nmom_z[0] < 30";

TCut Cut_dimuon_nmom10 = "dimuon_nmom_z[0] > 10";
TCut Cut_dimuon_nmom30 = "dimuon_nmom_z[0] > 30";
TCut Cut_dimuon_nmom50 = "dimuon_nmom_z[0] > 50";
TCut Cut_dimuon_nmom70 = "dimuon_nmom_z[0] > 70";