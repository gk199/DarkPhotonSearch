#include "NtuplePlotter.h"
#include "RegionCuts.h"

// -------------------------------------------------------------------------------------------------
void NtuplePlotterExample(){

	string path = "../../DarkQuest/e1039-analysis/SimHits/macro/output_";
	
	vector<string> filetags_signal = { "Aprime_DiMuon", "JPsi_DiMuon" };
	vector<string> filetags_all = {  "background", "Aprime_DiMuon", "JPsi_DiMuon" };
	vector<string> filetags_Aprime = { "Aprime_DiMuon" };
	vector<string> filetags_JPsi = { "JPsi_DiMuon" };
	vector<string> filetags_bkg = { "background" };

	// ----- Example 1 -----//
	// - Basic Booleans

	cout<<endl;
	cout<<" ---------- dimuon mass, few cuts ---------- "<<endl;
	cout<<endl;

	class NtuplePlotter plotter_example1( filetags_all, path );

	plotter_example1.SetTreeName( "Events" );	// TreeName
	plotter_example1.SetPlots({P_dimuon_mass_0}); // These "P_" variables are PlotParams structs defined in PlotParams.h
	plotter_example1.SetOutputFileTag("Aprime_JPsi"); // Your own special name :)
	plotter_example1.debug  		  = false; 	// Default = false
	plotter_example1.plot_norm 		  = true; 	// Default = true
	plotter_example1.plot_log  		  = true; 	// Default = true
	plotter_example1.plot_log_ratio   = false; 	// Default = false. Make bottom panel log scale
	plotter_example1.plot_log_x       = false; 	// Default = false. Plot log on the x axis
	plotter_example1.stamp_counts 	  = true;	// Default = false. Print event count and integral in legend
	plotter_example1.plot_grid 	  	  = true;	// Default = true. Draw grid lines on plot
	plotter_example1.run_fit   		  = true;	// Default = false. Fit core & tail
	plotter_example1.fit_type         = "igf_mean";
	plotter_example1.plot_cdf 		  = false;	// Default = false. Cumulative distribution function 
	plotter_example1.plot_reverse_cdf = false;	// Default = false. Cumulative distribution function 
	plotter_example1.use_weight       = false;	// Default = true, which uses weight branch when drawing non-normalized hists
	plotter_example1.Plot();					// This is what does stuff -- arguments: None/"", "ratio", "sig"/"ssqrtb"

	// ----- Example 2 -----//
	// - Adding Plots
	// - Setting cuts/selections
	// - Setting output file tag
	// - Aesthetics: Legend Location, NBins, colors, linestyles

	cout<<endl;
	cout<<" ---------- dimuon mass with various cuts ---------- "<<endl;
	cout<<endl;
	
	class NtuplePlotter plotter_example2( filetags_all, path );

	plotter_example2.SetPlots({ P_dimuon_mass_0 }); 
	plotter_example2.AddPlot( P_truth_dimuon_mass_0 );
	plotter_example2.SetTreeName( "Events" );			 					// Multiple Tree Names -- number must match number of input files (1:1), {"Events", "Events"}
	plotter_example2.plot_norm = false; 
	// plotter_example2.SetCuts("n_hits > 0"); 		                        // Apply cuts to all events
	// plotter_example2.SetSelectiveCuts("JPsi", "n_hits>1");			    // Apply this only to filetag names that include the string "JPsi"
	// plotter_example2.SetComparisonCuts({Cut_n_TruthDiMuon, Cut_fpga_trig}); // Apply cuts to overlay
	plotter_example2.SetComparisonCuts({Cut_dimuon_pos, Cut_nTracks, Cut_dimuon_pT_p, Cut_dimuon_pT_n});
	plotter_example2.SetOutputFileTag(""); 									// Your own special name :)
	plotter_example2.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );				// Manual Legend location
	plotter_example2.colors = {kBlack, kBlack, kBlack, kGray, kRed, kRed, kRed, kRed-4, kGreen+2, kGreen+2, kGreen+2, kGreen+3};		        // Your own colors (default kBlack + rainbow)
	plotter_example2.linestyle = {kSolid, kDotted, kDashed, kDashed, kSolid, kDotted, kDashed, kDashed, kSolid, kDotted, kDashed, kDashed}; 		// Your own linestyle (default kSolid)
	// plotter_example2.NBins = 15; 									 		// Default = 100
	plotter_example2.Plot();
	
	class NtuplePlotter plotter_example3( filetags_all, path );

	plotter_example3.SetPlots({ P_dimuon_mass_0 }); 
	plotter_example3.AddPlot( P_truth_dimuon_mass_0 );
	plotter_example3.SetTreeName( "Events" );			 					// Multiple Tree Names -- number must match number of input files (1:1), {"Events", "Events"}
	plotter_example3.plot_norm = false; 
	plotter_example3.SetComparisonCuts({"", Cut_mom, Cut_DT, Cut_chisq, Cut_hodo});
	plotter_example3.SetOutputFileTag("CutBased"); 									// Your own special name :)
	plotter_example3.SetLegendPosition( 0.5, 0.4, 0.88, 0.88 );				// Manual Legend location
	plotter_example3.colors = {kBlack, kGray, kBlack, kBlack, kGray, kRed, kRed-4, kRed, kRed, kRed-4, kGreen+2, kGreen+3, kGreen+2, kGreen+2, kGreen+3};		        // Your own colors (default kBlack + rainbow)
	plotter_example3.linestyle = {kSolid, kSolid, kDotted, kDashed, kDashed, kSolid, kSolid, kDotted, kDashed, kDashed, kSolid, kSolid, kDotted, kDashed, kDashed}; 		// Your own linestyle (default kSolid)
	plotter_example3.Plot();
	
	class NtuplePlotter plotter_example4( filetags_all, path );

	plotter_example4.SetPlots({ P_dimuon_mass_0 }); 
	plotter_example4.SetTreeName( "Events" );			 					// Multiple Tree Names -- number must match number of input files (1:1), {"Events", "Events"}
	plotter_example4.plot_norm = false; 
	plotter_example4.SetComparisonCuts({Cut_dimuon_nmom10, Cut_dimuon_nmom30, Cut_dimuon_nmom50, Cut_dimuon_nmom70});
	plotter_example4.SetOutputFileTag("EnergyCuts"); 									// Your own special name :)
	plotter_example4.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );				// Manual Legend location
	plotter_example4.colors = {kBlack, kBlack, kBlack, kGray, kRed, kRed, kRed, kRed-4, kGreen+2, kGreen+2, kGreen+2, kGreen+3};		        // Your own colors (default kBlack + rainbow)
	plotter_example4.linestyle = {kSolid, kDotted, kDashed, kDashed, kSolid, kDotted, kDashed, kDashed, kSolid, kDotted, kDashed, kDashed}; 		// Your own linestyle (default kSolid)
	plotter_example4.Plot();	

	// ----- Example 3 -----//
	// - Ratio plotting -- can be used for efficiency plots too

    cout<<endl;
	cout<<" ---------- All potential analysis variables ---------- "<<endl;
	cout<<endl;
	
	class NtuplePlotter plotter_example5( filetags_all, path );

	plotter_example5.SetPlots({ P_mass_res, P_hits_h1x, P_hits_h2x, P_hits_h3x, P_hits_h4x, P_hits_hodoscope_total, // hodoscope hits
								P_hits_d0x, P_hits_d2x, P_hits_d3px, P_hits_d3mx, P_hits_d3x_tot, P_hits_drift_tot, // drift chamber hits
								P_hits_dp1, P_hits_dp2, P_hits_dp_total, // dark photon hodoscope hits
								P_track_nhits, P_track_nhits_1, P_n_tracks, P_track_charge, P_track_quality, P_track_chisq, // tracking info
								P_dimuon_nmom_z_0, P_dimuon_pmom_z_0, P_dimuon_ppos_z_0, P_dimuon_npos_z_0, // dimuon muon momentum/position
								P_dimuon_chisq, P_dimuon_chisq_vx, P_dimuon_x_vtx, P_dimuon_y_vtx, P_dimuon_z_vtx, // dimuon vertex info
								P_hits_d0, P_hits_d1, P_hits_d2, P_hits_d3p, P_hits_d3m }); // drift chamber ? hits (total, not reconstructed)
	plotter_example5.SetTreeName( "Events" ); 
	plotter_example5.SetCuts(Cut_n_DiMuon);
	// plotter_example5.SetComparisonCuts({"", "dimuon_mass[0] > 0"});
	// plotter_example5.colors = {kBlack, kGray, kRed-4, kRed-9, kGreen+3, kGreen-3};
	// plotter_example5.SetOutputFileTag("Resolution");
	plotter_example5.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );
	plotter_example5.NBins = 30;
	plotter_example5.Plot("ratio");								 		    // Ratio panel

	cout<<endl;
	cout<<" ---------- Track vertex information -- efficiency with truth mass match cut ---------- "<<endl;
	cout<<endl;

	class NtuplePlotter plotter_example6( filetags_Aprime, path );
	plotter_example6.SetPlots({ P_track_pz_vtx }); 
	plotter_example6.SetTreeName( "Events" ); 
	plotter_example6.SetComparisonCuts({"", Cut_mass_res});
	plotter_example6.SetOutputFileTag("Efficiency"); 			
	plotter_example6.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );	
	plotter_example6.NBins = 15; 
	plotter_example6.plot_norm = false;
	plotter_example6.SetLegendNames({"Total (dark photon)", "Matches truth mass"});
	plotter_example6.Plot("efficiency");
	
	class NtuplePlotter plotter_example7( filetags_JPsi, path );
	plotter_example7.SetPlots({ P_track_pz_vtx }); 
	plotter_example7.SetTreeName( "Events" ); 
	plotter_example7.SetComparisonCuts({"", Cut_mass_res});
	plotter_example7.SetOutputFileTag("Efficiency"); 			
	plotter_example7.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );	
	plotter_example7.NBins = 15; 
	plotter_example7.plot_norm = false;
	plotter_example7.SetLegendNames({"Total (JPsi)", "Matches truth mass"});
	plotter_example7.Plot("efficiency");

	class NtuplePlotter plotter_example8( filetags_bkg, path );
	plotter_example8.SetPlots({ P_track_pz_vtx }); 
	plotter_example8.SetTreeName( "Events" ); 
	plotter_example8.SetComparisonCuts({"", Cut_mass_res});
	plotter_example8.SetOutputFileTag("Efficiency"); 			
	plotter_example8.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );	
	plotter_example8.NBins = 15; 
	plotter_example8.plot_norm = false;
	plotter_example8.SetLegendNames({"Total (bkg)", "Matches truth mass"});
	plotter_example8.Plot("efficiency");

	// ----- How do DP hodoscope hits vary? -----//
	class NtuplePlotter plotter_example9( filetags_Aprime, path );
	plotter_example9.SetPlots({ P_hits_dp1, P_hits_dp2, P_hits_dp_total }); 
	plotter_example9.SetTreeName( "Events" ); 
	plotter_example9.SetCuts(Cut_n_DiMuon);
	plotter_example9.SetComparisonCuts({"", "dimuon_npos_z[0] < 300", "dimuon_npos_z[0] >= 300 && dimuon_npos_z[0] < 400", "dimuon_npos_z[0] >= 400 && dimuon_npos_z[0] < 500", "dimuon_npos_z[0] >= 500"});
	plotter_example9.SetOutputFileTag("DispCuts");
	plotter_example9.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );
	plotter_example9.NBins = 30;
	plotter_example9.Plot("ratio");	

    // vars to consider plotting
    // P_dimuon_mass_0
    // P_truth_dimuon_mass_0
    // P_dimuon_pmom_z_0
    // P_mass_res
    // P_track_nhits_st1
    // P_track_pz_vtx

	// ----- Other Current Featues ----- //

	// - Fitting
	//		plotter_example.run_fit  = true;
	//		plotter_example.fit_type = "igf_sigma igf_mean"; 	// Options (you can combine them): "igf", "igf_sigma", "igf_mean", "tailfrac", "tail_spread", "exp_decay", "fixed_gaus";
	// - Plotting static histograms, like cutflows: 
	// 		plotter_example.PlotStaticHistogram("NoSel__jet0_energy");
	// - 2D Plotting:
	// 		plotter_example.Plot2D(jet0_energy, jet0_pt); X vs. Y
	// - Variable Bins -- BUT These are the same for all plots in a given instance of calling Plot()
	// 		plotter_example.SetVariableBins( {0, 10, 20, 30, 50, 75, 100, 150, 200, 300, 500} );
}