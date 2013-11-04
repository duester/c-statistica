#pragma once
#include "..\Util\ResourceUtil.h"
#include "..\Util\Util.h"

namespace Statistica{

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class Chart abstract{
	protected:
		Legend^ legend;
		array<double, 2>^ data;
		array<String^>^ columnHeaders;
		bool valid;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
		System::Drawing::Font^ titleFont;

		ChartArea^ createChartArea(String^ title);
		Label^ createLabel(String^ key);
		void setChartTitle(String^ key);
		virtual void drawChart() abstract;
	public:
		Chart(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
		void setData(array<double, 2>^ data, array<String^>^ columnHeaders);
		bool hasValidData();
		void draw();
		virtual void localizeTitles() abstract;
		virtual array<Control^>^ getControls() abstract;
	};
}
