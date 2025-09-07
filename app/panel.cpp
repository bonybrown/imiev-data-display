
#include "imgui/imgui.h"

extern font_biggest;

const float unit_offset = 0.86;
//ImVec2 text_tl( 10, 10 );
const int padding = 10;

ImU32 c1 = IM_COL32(90,90,90,255);
ImU32 c2 = IM_COL32(30,30,30,255);

// width is typically Display width / number of panels to show on the line
void UiPanel(int width, int height, char *label, char *value, char *units = NULL){
        ImVec2 wtl = ImGui::GetCursorScreenPos();
        ImVec2 tl(wtl.x + padding, wtl.y + padding);
        ImVec2 br(wtl.x + width - padding , wtl.y + height - padding);
        ImGui::GetWindowDrawList()->AddRectFilledMultiColor(tl, br, c1, c1, c2,c2);
	ImGui::BeginGroup();
        ImGui::SetNextItemWidth(width);
	auto labelSize = ImGui::CalcTextSize(label);
        ImGui::SetCursorPosX( padding + (width - labelSize.x ) * 0.5f);
        ImGui::Text( label );
        ImGui::PushFont( font_biggest );
        auto valueSize = ImGui::CalcTextSize(value);
        ImGui::PopFont();
        auto unitsSize = ImVec2;
	if( units ){
		unitsSize = ImGui::CalcTextSize(units);
	}
	float totalWidth = valueSize.x + unitsSize.x;
        ImGui::PushFont(font_biggest);
        ImGui::SetCursorPosX( padding + (width - totalWidth) * 0.5f );
        ImGui::Text( value );
        ImGui::PopFont();
        if( units ){
            ImGui::SameLine();
            ImGui::SetCursorPosY( ImGui::GetCursorPosY() - unitsSize.y + labelSize.y * unit_offset );
            ImGui::Text(units);
        }
	ImGui::EndGroup();

}
