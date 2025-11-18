#include "NtuplePlotter.h"
#include "RegionCuts.h"

// -------------------------------------------------------------------------------------------------
void NtuplePlotterExample(){

	string path = "../../DarkQuest/e1039-analysis/SimHits/macro/output_";
	
	vector<string> filetags_example1 = { "Aprime_DiMuon", "JPsi_DiMuon" };
	vector<string> filetags_Aprime = { "Aprime_DiMuon" };

	// ----- Example 1 -----//
	// - Basic Booleans

	cout<<endl;
	cout<<" ---------- EXAMPLE 1 ---------- "<<endl;
	cout<<endl;

	class NtuplePlotter plotter_example1( filetags_example1, path );

	plotter_example1.SetTreeName( "Events" );	// TreeName
	plotter_example1.SetPlots({P_dimuon_mass_0}); // These "P_" variables are PlotParams structs defined in PlotParams.h
	plotter_example1.SetOutputFileTag("Aprime_JPsi"); // Your own special name :)
	plotter_example1.debug  		  = true; 	// Default = false
	plotter_example1.plot_norm 		  = true; 	// Default = true
	plotter_example1.plot_log  		  = false; 	// Default = true
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
	cout<<" ---------- EXAMPLE 2 ---------- "<<endl;
	cout<<endl;
	
	vector<string> filetags_example2 = filetags_example1;

	class NtuplePlotter plotter_example2( filetags_example2, path );

	plotter_example2.SetPlots({ P_dimuon_mass_0 }); 
	plotter_example2.AddPlot( P_truth_dimuon_mass_0 );
	plotter_example2.SetTreeNames( {"Events", "Events"} ); 					// Multiple Tree Names -- number must match number of input files (1:1)
	plotter_example2.SetCuts("n_hits > 0"); 		                        // Apply cuts to all events
	plotter_example2.SetComparisonCuts({Cut_n_TruthDiMuon, Cut_fpga_trig}); // Apply cuts to overlay
	// plotter_example2.SetSelectiveCuts("JPsi", "n_hits>1");			    // Apply this only to filetag names that include the string "JPsi"
	plotter_example2.SetOutputFileTag("TruthCompare"); 						// Your own special name :)
	plotter_example2.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );				// Manual Legend location
	plotter_example2.colors = {kRed, kRed, kGreen+2, kGreen+2};		        // Your own colors (default kBlack + rainbow)
	plotter_example2.linestyle = {kDotted, kDashed, kDotted, kDashed}; 		// Your own linestyle (default kSolid)
	plotter_example2.NBins = 15; 									 		// Default = 100
	plotter_example2.Plot();								 	

	// ----- Example 3 -----//
	// - Ratio plotting -- can be used for efficiency plots too

    cout<<endl;
	cout<<" ---------- EXAMPLE 3 ---------- "<<endl;
	cout<<endl;
	
	vector<string> filetags_example3 = filetags_example1;

	class NtuplePlotter plotter_example3( filetags_example3, path );

	plotter_example3.SetPlots({ P_mass_res }); 
	plotter_example3.SetTreeName( "Events" ); 
	plotter_example3.SetOutputFileTag("Resolution");
	plotter_example3.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );
	plotter_example3.NBins = 30;
	plotter_example3.Plot("ratio");								 		    // Ratio panel

	cout<<endl;
	cout<<" ---------- EXAMPLE 4 ---------- "<<endl;
	cout<<endl;

	class NtuplePlotter plotter_example4( filetags_Aprime, path );

	plotter_example4.SetPlots({ P_track_pz_vtx }); 
	plotter_example4.SetTreeName( "Events" ); 
	plotter_example4.SetComparisonCuts({"", Cut_mass_res});
	plotter_example4.SetOutputFileTag("Efficiency"); 			
	plotter_example4.SetLegendPosition( 0.6, 0.7, 0.88, 0.88 );	
	plotter_example4.NBins = 15; 
	plotter_example4.plot_norm = false;
	plotter_example4.SetLegendNames({"total", "Matches truth mass"});
	plotter_example4.Plot("efficiency");	

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