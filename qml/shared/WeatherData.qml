pragma Singleton
import QtQuick 2.15

QtObject {

    readonly property string fetchedAt: "--"
    readonly property string overallSummary: "- - - - - - - - - - - - - - - -"

    // property string comfortLevel: {
    //     let comfort;

    //     if (temperature > 30 && humidity > 70) comfort = "Extremely Sweltering";
    //     else if (temperature > 25 && humidity > 65) comfort = "Sticky & Humid";
    //     else if (temperature >= 15 && temperature <= 24) comfort = "Pleasant";
    //     else if (temperature >= 5 && temperature < 15) comfort = "Cool";
    //     else if (temperature < 5 && temperature >= -10) comfort = "Bone-Chilling";
    //     else if (temperature < -10) comfort = "Freezing Danger";
    //     else comfort = "Varies";

    //     return "Comfort: " + comfort;
    // }

    // property string activityScore: {
    //     let activity;

    //     if (temperature < -5) activity = "Dangerously Cold";
    //     else if (temperature > 38) activity = "Extreme Heat Warning";
    //     else if (uvIndex >= 8 && cloudiness < 20) activity = "High Burn Risk";
    //     else if (condition === "Rain" || windSpeed > 15) activity = "Poor Conditions";
    //     else if (temperature >= 10 && temperature <= 28) activity = "Ideal for Outdoors";
    //     else activity = "Stay Alert";

    //     return "Activity: " + activity;
    // }

    // property string viewingCondition: {
    //     let view;

    //     if (visibility < 1) view = "Dense Fog";
    //     else if (visibility < 5) view = "Hazy / Low Visibility";
    //     else if (condition === "Snow") view = "Snow Blurriness";
    //     else if (cloudiness < 10 && visibility >= 10) view = "Crystal Clear";
    //     else if (cloudiness > 90) view = "Overcast Skies";
    //     else view = "Typical Clarity";

    //     return "View: " + view;
    // }

    // property string airQualityVibe: {
    //     let airQuality;

    //     if (visibility > 15 && windSpeed < 5) airQuality = "Crisp Air";
    //     else if (visibility < 8) airQuality = "Dusty / Hazy";
    //     else if (temperature < 0) airQuality = "Sharp / Frosty";
    //     else airQuality = "Fresh Breeze";

    //     return "AQ: " + airQuality;
    // }

    // property string overallSummary: comfortLevel + "   •   " + activityScore + "   •   " + viewingCondition + "   •   " + airQualityVibe
}
