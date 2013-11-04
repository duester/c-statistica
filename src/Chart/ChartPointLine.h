#pragma once
#include "Chart.h"

namespace Statistica{

	public ref class ChartPointLine abstract : public Chart{
	private:
		ColorDialog^ colorDialog;

		void color_Clicked(Object^  sender, EventArgs^  e);
	protected:
		Button^ color;

		virtual void drawChart() override;
	public:
		ChartPointLine(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
	};
}
