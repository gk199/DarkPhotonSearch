// -------------------------------------------------------------------------------------
struct PlotParams{
	string hist_name, title, label_x;
	double xmin, xmax;
};
typedef struct PlotParams PlotParams;

struct Hist1_Hist2_Cut{
	PlotParams Params1, Params2; 
	TCut cut;	
	Hist1_Hist2_Cut(PlotParams hist1, PlotParams hist2, TCut sel_cut)
	{
		Params1 = hist1;
		Params2 = hist2;
		cut = sel_cut;
	}
};

struct Hist1_Hist2{
	PlotParams Params1, Params2; 	
	Hist1_Hist2(PlotParams hist1, PlotParams hist2)
	{
		Params1 = hist1;
		Params2 = hist2;
	}
};

// Example:
// PlotParams P_VarName 	= {"VariableName", "Plot Title", "x label [units]", XMIN, XMAX };

// ----- Physics Variables ----- // 

// -------------------------------------------------------------------------------------
// kinematics
PlotParams P_dimuon_mass_0              = {"dimuon_mass[0]", "Dimuon mass for leading dimuons", "Mass [GeV]", 0, 10 };
PlotParams P_truth_dimuon_mass_0        = {"truthdimuon_mass[0]", "Dimuon mass for leading dimuons (truth)", "Mass [GeV]", 0, 10 };
PlotParams P_dimuon_nmom_z_0            = {"dimuon_nmom_z[0]", "Muon+ momentum (z) for leading dimuons", "p [GeV]", 0, 50 };
PlotParams P_dimuon_pmom_z_0            = {"dimuon_pmom_z[0]", "Muon- momentum (z) for leading dimuons", "p [GeV]", 0, 50 };
PlotParams P_dimuon_npos_z_0            = {"dimuon_npos_z[0]", "Muon+ position (-z) for leading dimuons", "p [GeV]", 0, 50 };
PlotParams P_dimuon_ppos_z_0         	= {"dimuon_ppos_z[0]", "Muon- position (+z) for leading dimuons", "p [GeV]", 0, 50 };
PlotParams P_mass_res                   = {"(dimuon_mass[0] - truthdimuon_mass[0]) / truthdimuon_mass[0]", "Dimuon mass resolution", "Mass Resolution [GeV]", -1, 1 };
PlotParams P_track_nhits_st1            = {"track_nhits_st1[0]", "Number of hits for leading track in station 1", "Number of Hits", 0, 50 };
PlotParams P_track_pz_vtx               = {"track_pz_vtx[0]", "Track pZ", "Track pZ [GeV]", 0, 100 };

// -------------------------------------------------------------------------------------
// hodoscope hits 
PlotParams P_hits_h1x                   = {"n_hits_h1x", "Number of hits in H1X hodoscope", "Number of Hits", 0, 20 };
PlotParams P_hits_h2x                   = {"n_hits_h2x", "Number of	 hits in H2X hodoscope", "Number of Hits", 0, 20 };
PlotParams P_hits_h3x                   = {"n_hits_h3x", "Number of	 hits in H3X hodoscope", "Number of Hits", 0, 20 };
PlotParams P_hits_h4x                   = {"n_hits_h4x", "Number of	 hits in H4X hodoscope", "Number of Hits", 0, 20 };
PlotParams P_hits_d0x                   = {"n_hits_d0x", "Number of hits in D0X drift chamber", "Number of Hits", 0, 20 };
PlotParams P_hits_d2x                   = {"n_hits_d2x", "Number of hits in	 D2X drift chamber", "Number of Hits", 0, 20 };		
PlotParams P_hits_d3px                  = {"n_hits_d3px", "Number of hits in D3+X drift chamber", "Number of Hits", 0, 10 };
PlotParams P_hits_d3mx                  = {"n_hits_d3mx", "Number of hits in D3-X drift chamber", "Number of Hits", 0, 10 };
PlotParams P_hits_dp1                   = {"n_hits_dp1", "Number of hits in DP1	hodoscope", "Number of Hits", 0, 20 };		
PlotParams P_hits_dp2                   = {"n_hits_dp2", "Number of hits in DP2 hodoscope", "Number of Hits", 0, 20 };	
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// tracking information
PlotParams P_track_nhits				= {"track_nhits[0]", "Number of hits for leading track", "Number of Hits", 0, 150 };
PlotParams P_track_nhits_1				= {"track_nhits[1]", "Number of hits for sub-leading track", "Number of Hits", 0, 150 };
PlotParams P_n_tracks					= {"n_tracks", "Number of reconstructed tracks", "Number of Tracks", 0, 20 };	
PlotParams P_track_charge				= {"track_charge[0]", "Charge of leading track", "Charge", -2, 2 };
PlotParams P_track_quality             = {"track_quality[0]", "Quality of leading track", "Quality", 0, 10 };
// -------------------------------------------------------------------------------------
