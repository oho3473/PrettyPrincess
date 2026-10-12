#pragma once
#include "Script.h"

/// <summary>
/// ¼Õ¼­Èñ
/// 
/// ÀÎ°ÔÀÓ ÆË¾÷ UI
/// </summary>
class PopUpUI : public Script
{
	// Reflection
	GENERATE_CLASS_TYPE_INFO(PopUpUI)

	// Serialize
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(PopUpUI, m_name, m_UID)
	void Serialize(nlohmann::json& json) override { to_json(json, *this); };
	void Deserialize(const nlohmann::json& json) override { if (!json.is_null()) from_json(json, *this); };

//»ý¼ºÀÚ¿Í ¼Ò¸êÀÚ ---------------------------------------------------------------------------------------
public:
	PopUpUI();
	~PopUpUI();

// ÄÄÆ÷³ÍÆ® ÇÔ¼ö ----------------------------------------------------------------------------------------
	virtual void Start() override;
	virtual void Update(double dt) override;
	virtual void Render(double dt);
	virtual std::shared_ptr<Component> Clone() const override;

// ¸â¹ö ÇÔ¼ö ----------------------------------------------------------------------------------------


// ¸â¹ö º¯¼ö ----------------------------------------------------------------------------------------
private:
	std::weak_ptr<IGraphics> m_igraphics;

public:
	Vector2 m_pos = Vector2(1920 / 2,1080 / 2);
	Vector2 m_size = Vector2(1920, 1080);

	bool m_isOn = false;
};