/*
 This project is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Deviation is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Deviation.  If not, see <http://www.gnu.org/licenses/>.
 */


#define DLG_STR_LEN (80 * 5)
static guiObject_t *dialog = NULL;
static char dlgstr[DLG_STR_LEN];
static u8 disable_safety = 0;//by default =0, means enable
static guiObject_t *current_selected_obj = NULL; // used for devo10 only

/******************/
/*  Safety Dialog */
/******************/
static void safety_ok_cb(u8 state, void * data)
{
    (void)state;
    (void)data;
    dialog = NULL;
    if (current_selected_obj != NULL)
        GUI_SetSelected(current_selected_obj);
    PROTOCOL_Init(1);
}

/**********************/
/* Low battery Dialog */
/**********************/
static void lowbatt_ok_cb(u8 state, void * data)
{
    (void)state;
    (void)data;
    if (current_selected_obj != NULL)
        GUI_SetSelected(current_selected_obj);
    dialog = NULL;
}


void PAGE_DisableSafetyDialog(u8 disable)
{
    disable_safety = disable;
}