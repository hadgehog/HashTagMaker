using System;
using System.Windows;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.ApplicationSettings;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using HashTagMakerNativeLibs;
using Windows.ApplicationModel.DataTransfer;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace HashTagMaker
{
    internal static class SettingsPage
    {
        public static void Initialise()
        {
            SettingsPane settingsPane = SettingsPane.GetForCurrentView();

            settingsPane.CommandsRequested += (s, e) =>
            {
                SettingsCommand settingsCommand = new SettingsCommand(
                  "SKINS_ID",
                  "Skins",
                  command =>
                  {
                      var flyout = new SettingsFlyout();
                      flyout.Title = "Select skin";

                      flyout.Content = new TextBlock()
                      {
                          Text = "Chose skin for your app",
                          TextAlignment = Windows.UI.Xaml.TextAlignment.Left,
                          TextWrapping = Windows.UI.Xaml.TextWrapping.Wrap,
                          FontSize = 14
                      };

                      flyout.Show();
                  }
                );
                e.Request.ApplicationCommands.Add(settingsCommand);
            };
        }
    }

    internal static class AboutPage
    {
        public static void Initialise()
        {
            SettingsPane settingsPane = SettingsPane.GetForCurrentView();

            settingsPane.CommandsRequested += (s, e) =>
            {
                SettingsCommand settingsCommand = new SettingsCommand(
                  "ABOUT_ID",
                  "About",
                  command =>
                  {
                      var flyout = new SettingsFlyout();
                      flyout.Title = "About";

                      flyout.Content = new TextBlock()
                      {
                          Text = "Created by Vladyslav Koshyl\r\nVersion 0.0.0.1 \r\n\r\nThis app helps you to create #hashtags for your events",
                          TextAlignment = Windows.UI.Xaml.TextAlignment.Left,
                          TextWrapping = Windows.UI.Xaml.TextWrapping.Wrap,
                          FontSize = 14
                      };

                      flyout.Show();
                  }
                );
                e.Request.ApplicationCommands.Add(settingsCommand);
            };
        }
    }

    public sealed partial class MainPage : Page
    {
        private Main engine;

        public MainPage()
        {
            this.InitializeComponent();
            this.MainTxtbx.Tapped += MainTxtbx_Tapped;
            this.MainTxtbx.AddHandler(TappedEvent, new TappedEventHandler(MainTxtbx_Tapped), true);

            SettingsPage.Initialise();
            AboutPage.Initialise();

            SettingsPane settingsPane = SettingsPane.GetForCurrentView();
            settingsPane.CommandsRequested += SettingsPane_CommandsRequested;

            this.engine = new Main();
        }

        private void SettingsPane_CommandsRequested(SettingsPane sender, SettingsPaneCommandsRequestedEventArgs args)
        {

        }

        private void CopyBtn_Click(object sender, RoutedEventArgs e)
        {
            var input = this.MainTxtbx.Text.ToString();

            if (input != null && this.engine != null)
            {
                DataPackage content = new DataPackage();
                content.SetText(input);

                Clipboard.SetContent(content);
            }
        }

        private void UntegBtn_Click(object sender, RoutedEventArgs e)
        {
            if (this.engine != null)
            {
                var baseString = this.engine.GetBaseString();

                if (baseString != null)
                {
                    this.MainTxtbx.Text = String.Empty;
                    this.MainTxtbx.Text = baseString;
                }
            }
        }

        private void HashTagBtn_Click(object sender, RoutedEventArgs e)
        {
            var input = this.MainTxtbx.Text.ToString();

            if (input != null && this.engine != null)
            {
                this.MainTxtbx.Text = String.Empty;
                this.engine.ClearCurrentSentence();
                this.engine.ParseInputString(input);
                this.MainTxtbx.Text = this.engine.GetHashtags();
            }
        }

        private void SaveBtn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void LoadBtn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void ExportBtn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void FavoriteBtn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void MainTxtbx_Tapped(object sender, TappedRoutedEventArgs e)
        {
            
        }

        private void ClearBtn_Click(object sender, RoutedEventArgs e)
        {
            this.MainTxtbx.Text = String.Empty;

            if (this.engine != null)
            {
                this.engine.ClearCurrentSentence();
            }
        }
    }
}
