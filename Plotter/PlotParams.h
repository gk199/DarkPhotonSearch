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

// Leading Jet 
// kinematics
PlotParams P_dimuon_mass_0              = {"dimuon_mass[0]", "Dimuon mass for leading dimuons", "Mass [GeV]", 0, 10 };
PlotParams P_truth_dimuon_mass_0        = {"truthdimuon_mass[0]", "Dimuon mass for leading dimuons (truth)", "Mass [GeV]", 0, 10 };
PlotParams P_dimuon_pmom_z_0            = {"dimuon_pmom_z[0]", "Dimuon momentum (z) for leading dimuons", "p [GeV]", 0, 50 };
PlotParams P_mass_res                   = {"(dimuon_mass[0] - truthdimuon_mass[0]) / truthdimuon_mass[0]", "Dimuon mass resolution", "Mass Resolution [GeV]", -1, 1 };
PlotParams P_track_nhits_st1            = {"track_nhits_st1[0]", "Number of hits for leading track in station 1", "Number of Hits", 0, 50 };
PlotParams P_track_pz_vtx               = {"track_pz_vtx[0]", "Track pZ", "Track pZ [GeV]", 0, 100 };