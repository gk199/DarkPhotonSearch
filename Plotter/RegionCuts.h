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

TString Cut_dimuon_nmom_under50 = "dimuon_nmom_z[0] < 50";
TString Cut_dimuon_pmom_under50 = "dimuon_pmom_z[0] < 50";
TCut Cut_dimuon_mom_under50 = "dimuon_pmom_z[0] < 50 && dimuon_nmom_z[0] < 50";
TString Cut_DT_hits_over2 = "n_hits_d0x > 1 && n_hits_d2x > 1 && n_hits_d3px > 1 && n_hits_d3mx > 1";
TString Cut_dimuon_chisq_over15 = "dimuon_chisq[0] > 15";
TString Cut_hodoscope_hits_over2 = "n_hits_h1x > 1 && n_hits_h2x > 1 && n_hits_h3x > 1 && n_hits_h4x > 1";

TCut Cut_mom	= 	( Cut_dimuon_nmom_under50 + AND + Cut_dimuon_pmom_under50 ).Data();
TCut Cut_DT	    = 	( Cut_dimuon_nmom_under50 + AND + Cut_dimuon_pmom_under50 + AND + Cut_DT_hits_over2 ).Data();
TCut Cut_chisq	= 	( Cut_dimuon_nmom_under50 + AND + Cut_dimuon_pmom_under50 + AND + Cut_DT_hits_over2 + AND + Cut_dimuon_chisq_over15 ).Data();
TCut Cut_hodo	= 	( Cut_dimuon_nmom_under50 + AND + Cut_dimuon_pmom_under50 + AND + Cut_DT_hits_over2 + AND + Cut_dimuon_chisq_over15 + AND + Cut_hodoscope_hits_over2 ).Data();